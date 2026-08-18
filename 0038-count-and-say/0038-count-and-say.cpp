class Solution {
public:
    void solve(int n, string &ans){
        if(n == 1){
            ans = "1";
            return;
        }
        solve(n-1, ans);
        string temp = "";
        int count = 1;
        for(int i=1;i<ans.size();i++){
            if(ans[i] == ans[i-1]) count++;
            else{
                temp += to_string(count) + ans[i-1];
                count = 1;
            }
        }
        temp += to_string(count) + ans.back();
        ans = temp;
    }
    string countAndSay(int n) {
        string ans = "";
        solve(n, ans);
        return ans;
    }
};
