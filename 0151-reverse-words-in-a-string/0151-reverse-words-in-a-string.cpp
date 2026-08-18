class Solution {
public:
    string reverseWords(string s) {
        stack <string> st;
        string x = "";
        for(char c:s){
            if(c != ' ') x += c;
            else{
                if(x != ""){
                    st.push(x);
                    x = "";
                }
            }
        }
        if(!x.empty()) st.push(x);
        string ans = "";
        while(!st.empty()){
            string y = st.top();
            st.pop();
            ans += y;
            if(!st.empty()) ans += ' ';
        }
        return ans;
    }
};
