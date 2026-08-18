class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0, left = 0, right = 0, ans = 0, odd = 0;
        for(right=0;right<nums.size();right++){
            if(nums[right] % 2){
                odd++;
                count = 0;
            }
            while(odd == k){
                count++;
                if(nums[left] % 2) odd--;
                left++;
            }
            ans += count;
        }
        return ans;
    }
};
