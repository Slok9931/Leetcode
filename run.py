import getpass
import json
import subprocess
import time
from pathlib import Path

import requests


GRAPHQL_URL = "https://leetcode.com/graphql/"

PAGE_SIZE = 100
SUBMISSION_PAGE_SIZE = 100
REQUEST_DELAY = 0.25


# ============================================================
# LeetCode GraphQL queries
# ============================================================

PROBLEMSET_QUERY = """
query problemsetQuestionListV2(
    $filters: QuestionFilterInput
    $limit: Int
    $skip: Int
    $categorySlug: String
) {
    problemsetQuestionListV2(
        filters: $filters
        limit: $limit
        skip: $skip
        categorySlug: $categorySlug
    ) {
        questions {
            id
            questionFrontendId
            title
            titleSlug
            difficulty
            paidOnly
            status
            topicTags {
                name
                slug
            }
        }
        totalLength
        hasMore
    }
}
"""


SUBMISSION_LIST_QUERY = """
query submissionList(
    $offset: Int!
    $limit: Int!
    $lastKey: String
    $questionSlug: String
) {
    submissionList(
        offset: $offset
        limit: $limit
        lastKey: $lastKey
        questionSlug: $questionSlug
    ) {
        lastKey
        hasNext
        submissions {
            id
            statusDisplay
            lang
            timestamp
            isPending
        }
    }
}
"""


SUBMISSION_DETAILS_QUERY = """
query submissionDetails($submissionId: Int!) {
    submissionDetails(submissionId: $submissionId) {
        code
        statusCode
        timestamp
        runtimeDisplay
        memoryDisplay
        question {
            title
            titleSlug
            difficulty
        }
    }
}
"""


# ============================================================
# LeetCode client
# ============================================================

class LeetCode:

    def __init__(self, session_cookie, csrf_cookie):

        self.session = requests.Session()

        self.session.cookies.set(
            "LEETCODE_SESSION",
            session_cookie,
            domain=".leetcode.com"
        )

        self.session.cookies.set(
            "csrftoken",
            csrf_cookie,
            domain=".leetcode.com"
        )

        self.headers = {
            "Content-Type": "application/json",
            "Accept": "application/json",
            "User-Agent": "Mozilla/5.0",
            "Origin": "https://leetcode.com",
            "Referer": "https://leetcode.com/",
            "x-csrftoken": csrf_cookie,
        }

    # --------------------------------------------------------
    # Generic GraphQL request
    # --------------------------------------------------------

    def graphql(self, query, variables, operation):

        response = self.session.post(
            GRAPHQL_URL,
            headers=self.headers,
            json={
                "operationName": operation,
                "variables": variables,
                "query": query,
            },
            timeout=30,
        )

        if response.status_code != 200:

            print("\nLeetCode returned:")
            print(response.text)

            raise RuntimeError(
                f"LeetCode HTTP error: {response.status_code}"
            )

        try:
            data = response.json()
        except Exception:

            print("\nInvalid JSON returned by LeetCode:")
            print(response.text)

            raise

        if "errors" in data:

            print("\nGraphQL error:")
            print(
                json.dumps(
                    data["errors"],
                    indent=2
                )
            )

            raise RuntimeError(
                "GraphQL request failed"
            )

        return data["data"]

    # --------------------------------------------------------
    # Get all solved problems
    # --------------------------------------------------------

    def get_solved_problems(self):

        print("\nFetching solved problems...")

        solved = []
        all_questions = []

        skip = 0

        while True:

            data = self.graphql(
                PROBLEMSET_QUERY,
                {
                    "filters": {
                        "filterCombineType": "ALL"
                    },
                    "limit": PAGE_SIZE,
                    "skip": skip,
                    "categorySlug": "all-code-essentials",
                },
                "problemsetQuestionListV2",
            )

            result = data[
                "problemsetQuestionListV2"
            ]

            questions = result[
                "questions"
            ]
            all_questions.extend(questions)

            for question in questions:

                if question.get("status") == "SOLVED":

                    solved.append(question)

            scanned = min(
                skip + len(questions),
                result["totalLength"]
            )

            print(
                f"  Scanned {scanned}/{result['totalLength']} "
                f"| Solved: {len(solved)}"
            )

            if not result["hasMore"]:

                break

            skip += PAGE_SIZE

            time.sleep(
                REQUEST_DELAY
            )

        # Remove duplicate slugs just in case.

        unique = {}

        for problem in solved:

            unique[
                problem["titleSlug"]
            ] = problem

        cache_path = Path(".leethub_problem_cache.json")

        with open(cache_path, "w", encoding="utf-8") as f:
            json.dump(all_questions, f, indent=2, ensure_ascii=False)

        print(
         f"\nSaved {len(all_questions)} LeetCode problems "
         f"to {cache_path}"
        )
        return list(unique.values())

    # --------------------------------------------------------
    # Find latest accepted C++ submission
    # --------------------------------------------------------

    def get_cpp_submission(self, slug):

        data = self.graphql(
            SUBMISSION_LIST_QUERY,
            {
                "offset": 0,
                "limit": SUBMISSION_PAGE_SIZE,
                "lastKey": None,
                "questionSlug": slug,
            },
            "submissionList",
        )

        result = data["submissionList"]

        submissions = result[
            "submissions"
        ]

        accepted_cpp = []

        for submission in submissions:

            if (
                submission.get("statusDisplay")
                == "Accepted"
                and submission.get("lang")
                == "cpp"
            ):

                accepted_cpp.append(
                    submission
                )

        if not accepted_cpp:

            return None

        # Newest accepted submission first.

        accepted_cpp.sort(
            key=lambda x: int(
                x["timestamp"]
            ),
            reverse=True
        )

        return accepted_cpp[0]

    # --------------------------------------------------------
    # Get actual source code
    # --------------------------------------------------------

    def get_submission_code(
        self,
        submission_id
    ):

        data = self.graphql(
            SUBMISSION_DETAILS_QUERY,
            {
                "submissionId": int(
                    submission_id
                )
            },
            "submissionDetails",
        )

        details = data[
            "submissionDetails"
        ]

        return details.get("code")


# ============================================================
# Git helpers
# ============================================================

def run_git(repo, command):

    result = subprocess.run(
        ["git"] + command,
        cwd=repo,
        text=True,
        capture_output=True,
    )

    if result.returncode != 0:

        print(result.stderr)

        raise RuntimeError(
            "Git command failed: "
            + " ".join(command)
        )

    return result.stdout.strip()


# ============================================================
# Main
# ============================================================

def main():

    print("=" * 72)
    print("        LeetCode -> GitHub Bulk Solution Importer")
    print("=" * 72)

    username = input(
        "\nLeetCode username: "
    )

    session_cookie = getpass.getpass(
        "LEETCODE_SESSION: "
    )

    csrf_cookie = getpass.getpass(
        "csrftoken: "
    )

    repo_input = input(
        "Path to your local LeetCode Git repository "
        "[default: ~/LeetCode]: "
    )

    repo = Path(
        repo_input or "~/LeetCode"
    ).expanduser().resolve()

    print(
        f"\nUsername: {username}"
    )

    print(
        f"Repository: {repo}"
    )

    # --------------------------------------------------------
    # Check Git repository
    # --------------------------------------------------------

    if not (repo / ".git").exists():

        raise RuntimeError(
            f"{repo} is not a Git repository."
        )

    # --------------------------------------------------------
    # Pull latest GitHub changes
    # --------------------------------------------------------

    print(
        "\nUpdating local repository from GitHub..."
    )

    run_git(
        repo,
        [
            "pull",
            "--rebase",
            "origin",
            "main"
        ]
    )

    print(
        "  GitHub -> local: OK"
    )

    # --------------------------------------------------------
    # Create LeetCode client
    # --------------------------------------------------------

    leetcode = LeetCode(
        session_cookie,
        csrf_cookie
    )

    # --------------------------------------------------------
    # Get solved problems
    # --------------------------------------------------------

    print(
        "\nChecking LeetCode session..."
    )

    solved = leetcode.get_solved_problems()

    print(
        f"\nFound {len(solved)} solved problems."
    )

    if not solved:

        print(
            "No solved problems found."
        )

        return

    # --------------------------------------------------------
    # Import
    # --------------------------------------------------------

    print(
        "\nStarting C++ solution import..."
    )

    print(
        "Existing files will be skipped."
    )

    print()

    created = 0
    already_exists = 0
    no_cpp = 0
    failed = 0

    for index, problem in enumerate(
        solved,
        start=1
    ):

        frontend_id = str(
            problem[
                "questionFrontendId"
            ]
        )

        number = frontend_id.zfill(4)

        slug = problem[
            "titleSlug"
        ]

        folder_name = (
            f"{number}-{slug}"
        )

        file_path = (
            repo
            / folder_name
            / f"{folder_name}.cpp"
        )

        print(
            f"[{index}/{len(solved)}] "
            f"{folder_name}",
            end=" "
        )

        # ----------------------------------------------------
        # Don't overwrite existing solution
        # ----------------------------------------------------

        if file_path.exists():

            print(
                "SKIP (already exists)"
            )

            already_exists += 1

            continue

        try:

            # ------------------------------------------------
            # Find accepted C++ submission
            # ------------------------------------------------

            submission = (
                leetcode.get_cpp_submission(
                    slug
                )
            )

            if submission is None:

                print(
                    "SKIP (no accepted C++ submission)"
                )

                no_cpp += 1

                continue

            # ------------------------------------------------
            # Get source code
            # ------------------------------------------------

            code = (
                leetcode.get_submission_code(
                    submission["id"]
                )
            )

            if not code:

                print(
                    "FAILED (empty source code)"
                )

                failed += 1

                continue

            # ------------------------------------------------
            # Write file
            # ------------------------------------------------

            file_path.parent.mkdir(
                parents=True,
                exist_ok=True
            )

            file_path.write_text(
                code.rstrip() + "\n",
                encoding="utf-8"
            )

            print(
                "OK"
            )

            created += 1

            time.sleep(
                REQUEST_DELAY
            )

        except KeyboardInterrupt:

            print(
                "\n\nImport cancelled."
            )

            break

        except Exception as error:

            print(
                f"FAILED: {error}"
            )

            failed += 1

    # --------------------------------------------------------
    # Summary
    # --------------------------------------------------------

    print()
    print("=" * 72)
    print("IMPORT COMPLETE")
    print("=" * 72)

    print(
        f"Created:             {created}"
    )

    print(
        f"Already existed:     {already_exists}"
    )

    print(
        f"No accepted C++:     {no_cpp}"
    )

    print(
        f"Failed:              {failed}"
    )

    # --------------------------------------------------------
    # Git status
    # --------------------------------------------------------

    if created == 0:

        print(
            "\nNo new files were created."
        )

        return

    print(
        "\nGit status:"
    )

    status = run_git(
        repo,
        [
            "status",
            "--short"
        ]
    )

    print(
        status
    )

    # --------------------------------------------------------
    # Ask before commit
    # --------------------------------------------------------

    answer = input(
        "\nCommit and push these solutions? [y/N]: "
    ).strip().lower()

    if answer != "y":

        print(
            "\nFiles have been created locally."
        )

        print(
            "Nothing was pushed to GitHub."
        )

        return

    # --------------------------------------------------------
    # Commit
    # --------------------------------------------------------

    print(
        "\nCreating Git commit..."
    )

    run_git(
        repo,
        ["add", "."]
    )

    run_git(
        repo,
        [
            "commit",
            "-m",
            "Import previous LeetCode solutions"
        ]
    )

    # --------------------------------------------------------
    # Push
    # --------------------------------------------------------

    print(
        "\nPushing to GitHub..."
    )

    run_git(
        repo,
        [
            "push",
            "origin",
            "main"
        ]
    )

    print()
    print("=" * 72)
    print("SUCCESS")
    print("=" * 72)

    print(
        f"{created} LeetCode solutions pushed to GitHub."
    )


if __name__ == "__main__":

    try:

        main()

    except KeyboardInterrupt:

        print(
            "\nCancelled."
        )

    except Exception as error:

        print(
            f"\nERROR: {error}"
        )
