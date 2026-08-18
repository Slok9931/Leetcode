class Solution {
public:
    string solve(string s){
        stack <char> st;
        for(char c:s){
            if(c != '#') st.push(c);
            else{
                if(!st.empty()) st.pop();
            }
        }
        string ans = "";
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
    }
    bool backspaceCompare(string s, string t) {
        s = solve(s);
        t = solve(t);
        if(s == t) return true;
        else return false;
    }
};
