class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long ans = INT_MIN, sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > ans) ans = sum;
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};
