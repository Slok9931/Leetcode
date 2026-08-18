class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans = 0, n = s.size();
        vector<int> mp(256, -1);
        while(right < n){
            if(mp[s[right]] != -1) left = max(mp[s[right]]+1, left);
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
