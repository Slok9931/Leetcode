class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    void solve(string s, int index, vector<string> &curr, vector <vector <string>> &ans){
        if(index == s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i=index+1;i<=s.length();i++){
            if(isPalindrome(s, index, i-1)){
                curr.push_back(s.substr(index, i - index));
                solve(s, i, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector <vector <string>> ans;
        vector <string> curr;
        solve(s, 0, curr, ans);
        return ans;
    }
};
