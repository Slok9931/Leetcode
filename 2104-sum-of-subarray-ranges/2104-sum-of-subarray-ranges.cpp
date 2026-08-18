class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
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
        long long sumSmall = 0;
        for(int i=0;i<n;i++){
            sumSmall += static_cast<long long>(i-left[i]) * (right[i]-i) * nums[i];
        }
        s = stack <int> ();
        left.assign(n, -1);
        right.assign(n, n);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()] < nums[i]) s.pop();
            if(!s.empty()) left[i] = s.top();
            s.push(i);
        }
        s = stack <int> ();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()] <= nums[i]) s.pop();
            if(!s.empty()) right[i] = s.top();
            s.push(i);
        }
        long long sumLarge = 0;
        for(int i=0;i<n;i++){
            sumLarge += static_cast<long long>(i-left[i]) * (right[i]-i) * nums[i];
        }
        return abs(sumLarge - sumSmall);
    }
};
