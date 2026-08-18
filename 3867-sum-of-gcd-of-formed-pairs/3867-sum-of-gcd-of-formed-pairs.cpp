class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        long long maxi = nums[0];
        vector<long long> prefixGcd(n);
        prefixGcd[0] = maxi;
        for(int i=1;i<n;i++){
            if(nums[i] > maxi) maxi = nums[i];
            prefixGcd[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0, j = n-1;
        long long ans = 0;
        while(i < j){
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};
