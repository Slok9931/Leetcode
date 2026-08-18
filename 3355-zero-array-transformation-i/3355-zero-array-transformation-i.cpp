class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1,0);
        int k = queries.size();
        for(int i=0;i<k;i++) {
            diff[queries[i][0]]--;
            diff[queries[i][1]+1]++;
        }
        int sum=0;
        bool x = true;
        for(int i=0;i<n;i++) {
            sum+=diff[i];
            if( sum+nums[i] > 0 ) x = false;
        }
        return x;
    }
};
