class Solution {
public:
    void solve(vector<int>& candidates, int target, vector <vector <int>> &ans, vector <int> &comb, int index, int total){
        if(total == target){
            ans.push_back(comb);
            return;
        }
        if(total > target || index >= candidates.size()) return;
        comb.push_back(candidates[index]);
        solve(candidates, target, ans, comb, index, total + candidates[index]);
        comb.pop_back();
        solve(candidates, target, ans, comb, index + 1, total);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int>> ans;
        vector <int> comb;
        solve(candidates, target, ans, comb, 0, 0);
        return ans;
    }
};
