class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length() < t.length()) return "";
        vector<int>freq(128, 0);
        for(char c:t) freq[c]++;
        int left = 0, right = 0, ans = INT_MAX, index = 0, count = t.length();
        while(right < s.size()){
            if(freq[s[right++]]-- > 0) count--;
            while(count == 0){
                if(right - left < ans){
                    index = left;
                    ans = right - left;
                }
                if(freq[s[left++]]++ == 0) count++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(index, ans);
    }
};
