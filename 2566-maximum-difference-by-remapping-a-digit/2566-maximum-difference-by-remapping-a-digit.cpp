class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char x, y;
        string maxi = "", mini = "";
        for(char c:s){
            if(c != '9'){
                x = c;
                break;
            }
        }
        for(char c:s){
            if(c != '0'){
                y = c;
                break;
            }
        }
        for (char c : s) {
            maxi += (c == x) ? '9' : c;
            mini += (c == y) ? '0' : c;
        }
        return stoi(maxi) - stoi(mini);
    }
};
