class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, ans = nums.size();
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        if(sum < target) return 0;
        sum = 0;
        for(right = 0; right < nums.size();right++){
            sum += nums[right];
            if(sum >= target) ans = min(ans, right - left + 1);
            while(sum >= target){
                sum -= nums[left];
                left++;
                if(sum >= target) ans = min(ans, right - left + 1);
            }
        }
        return ans;
    }
};
