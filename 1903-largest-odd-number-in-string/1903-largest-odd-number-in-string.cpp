class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        while(i >= 0){
            char c = num[i];
            if(c == '1' || c == '3' || c == '5' || c == '7' || c == '9') break;
            i--;
        }
        return num.substr(0, i+1); 
    }
};
