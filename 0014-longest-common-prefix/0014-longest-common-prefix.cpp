class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans = strs[0];
        int n = ans.length();
        for(int i=1;i<strs.size();i++){
            string s = strs[i];
            while(n > s.size() || ans != s.substr(0, n)){
                n--;
                if(n == 0) return "";
                ans = ans.substr(0, n);
            }
        }
        return ans;
    }
};
