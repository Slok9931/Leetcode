class Solution {
public:
    string expand(string s, int left, int right){
        while(left >=0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        string ans = s.substr(0,1);
        for(int i=0;i<s.length()-1;i++){
            string odd = expand(s, i, i);
            string even = expand(s, i, i+1);
            if(odd.length() > ans.length()) ans = odd;
            if(even.length() > ans.length()) ans = even;
        }
        return ans;
    }
};
