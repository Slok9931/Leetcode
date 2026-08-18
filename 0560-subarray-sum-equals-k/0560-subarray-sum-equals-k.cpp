class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int ans = 0, sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(prefix.find(sum - k) != prefix.end()) ans += prefix[sum-k];
            prefix[sum]++;
        }
        return ans;
    }
};
