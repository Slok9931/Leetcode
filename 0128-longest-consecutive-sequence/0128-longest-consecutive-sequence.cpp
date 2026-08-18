class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i:nums) set.insert(i);
        int ans = 0;
        for(int i:set){
            if(set.find(i-1) != set.end()) continue;
            else{
                int len = 1;
                while(set.find(i+len) != set.end()) len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
