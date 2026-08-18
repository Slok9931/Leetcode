class Solution {
public:
    int subarrayWithAtmostKDistinct(vector<int> &nums, int k){
        unordered_map<int, int> freq;
        int left = 0, right = 0, count = 0, ans = 0;
        for(right=0;right<nums.size();right++){
            freq[nums[right]]++;
            if(freq[nums[right]] == 1) count++;
            while(count > k && left < nums.size()){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) count--;
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtmostKDistinct(nums, k) - subarrayWithAtmostKDistinct(nums, k-1);
    }
};
