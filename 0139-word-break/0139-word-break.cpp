class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int maxLen = 0;

        unordered_set<string> dict;

        for (const string& word : wordDict) {
            dict.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (!dp[i]) {
                continue;
            }

            for (int len = 1; len <= maxLen && i + len <= n; len++) {
                string word = s.substr(i, len);

                if (dict.count(word)) {
                    dp[i + len] = true;
                }
            }
        }

        return dp[n];
    }
};