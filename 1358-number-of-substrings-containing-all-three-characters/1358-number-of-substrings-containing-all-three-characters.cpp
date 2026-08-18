class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, left = 0;
        int a = 0, b = 0, c = 0;
        for(int right=0;right<s.size();right++){
            if(s[right] == 'a') a++;
            else if(s[right] == 'b') b++;
            else if(s[right] == 'c') c++;
            while(a && b && c){
                ans += s.size() - right;
                if(s[left] == 'a') a--;
                else if(s[left] == 'b') b--;
                else if(s[left] == 'c') c--;
                left++;
            }
        }
        return ans;
    }
};
