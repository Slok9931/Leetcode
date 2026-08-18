const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector <int> left(n, -1), right(n, n);
        stack <int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            if(!s.empty()) left[i] = s.top();
            s.push(i);
        }
        s = stack <int> ();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()] > nums[i]) s.pop();
            if(!s.empty()) right[i] = s.top();
            s.push(i);
        }
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += static_cast<long long>(i-left[i]) * (right[i]-i) * nums[i] % MOD;
            sum %= MOD;
        }
        return sum;
    }
};
