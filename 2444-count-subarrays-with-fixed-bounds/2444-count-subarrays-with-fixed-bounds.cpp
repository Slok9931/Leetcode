class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int left = -1, mini = -1, maxi = -1;
        int n = nums.size();
        for(int right=0;right<n;right++){
            if(nums[right] > maxK || nums[right] < minK) left = right;
            if(nums[right] == maxK) maxi = right;
            if(nums[right] == minK) mini = right;
            count += max(0, min(mini, maxi)-left);
        }
        return count;
    }
};
