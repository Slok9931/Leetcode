class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, prev = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > prev) ans = max(ans, nums[i]-prev);
            else prev = nums[i];
        }
        return ans;
    }
};
