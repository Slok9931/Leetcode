import json
import subprocess
from datetime import datetime, timezone
from pathlib import Path


REPO = Path.cwd()
TOPICS_DIR = REPO / "Topics"
CACHE_FILE = REPO / ".leethub_problem_cache.json"


def now_iso():
    return (
        datetime.now(timezone.utc)
        .isoformat(timespec="milliseconds")
        .replace("+00:00", "Z")
    )


def git_sha(path):
    result = subprocess.run(
        ["git", "hash-object", str(path)],
        cwd=REPO,
        capture_output=True,
        text=True,
        check=True,
    )

    return result.stdout.strip()


def load_json(path):
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def save_json(path, data):
    with open(path, "w", encoding="utf-8") as f:
        json.dump(
            data,
            f,
            indent=2,
            ensure_ascii=False,
        )
        f.write("\n")


def main():

    print("=" * 72)
    print("        LeetHub-Neo Metadata Migration")
    print("=" * 72)

    if not CACHE_FILE.exists():
        print("\nERROR: .leethub_problem_cache.json not found.")
        return

    cache = load_json(CACHE_FILE)

    # Only problems that are actually solved.
    solved = [
        q
        for q in cache
        if q.get("status") == "SOLVED"
    ]

    print(f"\nSolved problems in LeetCode cache: {len(solved)}")

    # ------------------------------------------------------------
    # Load existing topic metadata
    # ------------------------------------------------------------

    topic_data = {}

    for path in TOPICS_DIR.glob("*/problems.json"):
        try:
            topic_data[path] = load_json(path)
        except Exception as e:
            print(f"ERROR reading {path}: {e}")
            return

    print(f"Topic metadata files found: {len(topic_data)}")

    # Track changes.
    modified = set()

    added = 0
    already_exists = 0
    missing_solution = 0

    # ------------------------------------------------------------
    # Process every solved problem
    # ------------------------------------------------------------

    for question in solved:

        frontend_id = str(
            question["questionFrontendId"]
        )

        title = question["title"]
        slug = question["titleSlug"]
        difficulty = question["difficulty"].capitalize()

        try:
            number = int(frontend_id)
            problem_name = f"{number:04d}-{slug}"
        except ValueError:
            problem_name = f"{frontend_id}-{slug}"

        solution_dir = REPO / problem_name

        cpp_file = (
            solution_dir
            / f"{problem_name}.cpp"
        )

        # We only migrate problems for which our bulk
        # importer actually created a C++ solution.
        if not cpp_file.exists():

            continue

        # --------------------------------------------------------
        # Calculate Git blob SHA
        # --------------------------------------------------------

        sha = git_sha(cpp_file)

        solution = {
            "language": "C++",
            "extension": ".cpp",
            "filename": f"{problem_name}.cpp",
            "path": f"{problem_name}/{problem_name}.cpp",
            "sha": sha,
            "lastSyncedAt": now_iso(),
        }

        # --------------------------------------------------------
        # Build Neo problem object
        # --------------------------------------------------------

        problem_entry = {
            "frontendId": frontend_id,
            "title": title,
            "slug": slug,
            "problemName": problem_name,
            "difficulty": difficulty,
            "leetcodeUrl": (
                f"https://leetcode.com/problems/{slug}/"
            ),
            "folderPath": f"{problem_name}/",
            "readmePath": f"{problem_name}/README.md",
            "solutions": [
                solution
            ],
        }

        # --------------------------------------------------------
        # Add problem to every LeetCode topic
        # --------------------------------------------------------

        for tag in question.get("topicTags", []):

            topic_slug = tag["slug"]

            topic_file = (
                TOPICS_DIR
                / topic_slug
                / "problems.json"
            )

            if topic_file not in topic_data:

                print(
                    f"WARNING: Topic file missing: "
                    f"Topics/{topic_slug}/problems.json"
                )

                continue

            data = topic_data[topic_file]

            problems = data.setdefault(
                "problems",
                []
            )

            # Check if Neo already knows this problem.
            existing = None

            for p in problems:

                if (
                    p.get("problemName")
                    == problem_name
                ):
                    existing = p
                    break

            if existing is not None:

                already_exists += 1

                # We don't overwrite existing Neo metadata.
                continue

            problems.append(
                problem_entry
            )

            modified.add(topic_file)

            added += 1

            print(
                f"ADD  {problem_name:<65} "
                f"-> {topic_slug}"
            )

    # ------------------------------------------------------------
    # Save changes
    # ------------------------------------------------------------

    timestamp = now_iso()

    for path in modified:

        data = topic_data[path]

        data["updatedAt"] = timestamp

        save_json(
            path,
            data
        )

    # ------------------------------------------------------------
    # Summary
    # ------------------------------------------------------------

    print()
    print("=" * 72)
    print("Migration complete")
    print("=" * 72)

    print(
        f"New metadata entries : {added}"
    )

    print(
        f"Already existed      : {already_exists}"
    )

    print(
        f"Topic files modified : {len(modified)}"
    )

    print()
    print(
        "README.md was NOT modified."
    )


if __name__ == "__main__":
    main()
