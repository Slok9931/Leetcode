class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k){
        int n=nums.size();
        long long ans = 0 ;
        int sum = 0 ;
        map<int,long long> mp ;
        mp[0]++ ;
        for(int i=0;i<n;i++){
            sum += (nums[i]%mod == k) ;
            sum = sum % mod ;
            if(mp.find((sum-k+mod)%mod) != mp.end()) ans += mp[(sum-k+mod)%mod] ;
            mp[sum]++ ;
        }
        return ans ;
    }
};
