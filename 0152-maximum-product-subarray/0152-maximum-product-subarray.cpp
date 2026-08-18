class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int maxi = 1, mini = 1;
        for(int i:nums){
            int temp = maxi * i;
            maxi = max({temp, mini*i, i});
            mini = min({temp, mini*i, i});
            ans = max(ans, maxi);
        }
        return ans;
    }
};
