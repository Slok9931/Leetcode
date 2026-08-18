class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int index){
        ans.push_back(subset);
        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            solve(nums, ans, subset, i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <int> subset;
        vector <vector <int>> ans;
        solve(nums, ans, subset, 0);
        return ans;
    }
};
