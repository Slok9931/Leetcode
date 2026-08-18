class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack <char> st;
        for(char c:s){
            if(st.empty() && c == '(') st.push(c);
            else if(!st.empty() && c == '('){
                st.push(c);
                ans += c;
            }
            else if(!st.empty() && c == ')'){
                st.pop();
                if(!st.empty()) ans += c;
            }
        }
        return ans;
    }
};
