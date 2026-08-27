class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        string ans;
        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            } 
            else {
                for (int j = x + 1; j < 26; j++) {
                    if (freq[j] > 0) {
                        ans += char('a' + j);
                        freq[j]--;
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }
                        return ans;
                    }
                }
                break;
            }
        }
        while (!ans.empty()) {
            char last = ans.back();
            ans.pop_back();
            freq[last - 'a']++;
            int x = last - 'a';
            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    string result = ans;
                    result += char('a' + j);
                    freq[j]--;
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            result += char('a' + k);
                            freq[k]--;
                        }
                    }
                    return result;
                }
            }
        }
        return "";
    }
};