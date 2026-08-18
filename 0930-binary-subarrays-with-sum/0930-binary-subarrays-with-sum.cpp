class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
    int solve(vector<int>&nums, int val){
        int left = 0, sum = 0, ans = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum > val && left <= right){
                sum -= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
