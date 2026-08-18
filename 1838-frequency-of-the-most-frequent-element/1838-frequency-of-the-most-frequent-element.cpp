class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        long long currSum = 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        for(int right=0;right<nums.size();right++){
            currSum += nums[right];
            while(currSum+k < static_cast<long long>(nums[right])*(right-left+1)){
                currSum -= nums[left];
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
