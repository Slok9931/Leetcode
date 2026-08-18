class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.size();
        for(char c = 'A'; c <= 'Z'; c++){
            int left = 0, right = 0, count = 0;
            while(right < n){
                if(s[right] == c) right++;
                else if(count < k){
                    right++;
                    count++;
                }
                else if(s[left] == c) left++;
                else{
                    left++;
                    count--;
                }
                ans = max(ans, right-left);
            }
        }
        return ans;
    }
};
