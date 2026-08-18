class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;

        for (string str : logs) {
            if (str == "../") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (str != "./") {
                s.push(str);
            }
        }
        return s.size();
    }
};
