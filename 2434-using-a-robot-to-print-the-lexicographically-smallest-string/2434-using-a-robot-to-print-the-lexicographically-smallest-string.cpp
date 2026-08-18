class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string result, t;
        vector<char> min_suffix(n);
        min_suffix[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i)
            min_suffix[i] = min(s[i], min_suffix[i + 1]);
        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]);
            while (!t.empty() && (i == n - 1 || t.back() <= min_suffix[i + 1])) {
                result += t.back();
                t.pop_back();
            }
        }
        return result;
    }
};
