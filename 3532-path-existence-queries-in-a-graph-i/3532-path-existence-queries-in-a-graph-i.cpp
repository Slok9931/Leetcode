class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int count = 0;
        for(int i=1;i<n;i++){
            if(abs(nums[i] - nums[i-1]) > maxDiff) count++;
            component[i] = count;
        }
        vector<bool> ans;
        for(auto i:queries) ans.push_back(component[i[0]] == component[i[1]]);
        return ans;
    }
};
