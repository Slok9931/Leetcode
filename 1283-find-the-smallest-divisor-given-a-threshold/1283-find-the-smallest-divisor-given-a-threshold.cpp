class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(s <= e){
            int mid = s + (e-s)/2;
            int sum = 0;
            for(int i=0;i<nums.size();i++) sum += (nums[i] + mid - 1) / mid;
            if(sum <= threshold){
                ans = min(ans, mid);
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};
