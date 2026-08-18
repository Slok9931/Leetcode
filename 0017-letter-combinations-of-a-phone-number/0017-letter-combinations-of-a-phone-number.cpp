class Solution {
public:
    void solve(string digits, int index, string curr, vector<string>& ans, unordered_map<char, string> mp){
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters = mp.at(digits[index]);
        for(char letter : letters) solve(digits, index + 1, curr + letter, ans, mp);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        solve(digits, 0, "", ans, mp);
        return ans;
    }
};
