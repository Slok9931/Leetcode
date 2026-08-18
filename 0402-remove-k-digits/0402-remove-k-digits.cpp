class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for (char c : num) {
            while (!s.empty() && k > 0 && s.top() > c) {
                s.pop();
                k--;
            }
            s.push(c);
        }
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') {
            idx++;
        }
        ans = ans.substr(idx);

        return ans.empty() ? "0" : ans;
    }
};
