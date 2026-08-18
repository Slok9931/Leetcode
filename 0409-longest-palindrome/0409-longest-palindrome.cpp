class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> chars;
        int ans = 0;
        for(char c:s){
            if(chars.find(c) != chars.end()){
                chars.erase(c);
                ans += 2;
            }
            else chars.insert(c);
        }
        if(!chars.empty()) ans += 1;
        return ans;
    }
};
