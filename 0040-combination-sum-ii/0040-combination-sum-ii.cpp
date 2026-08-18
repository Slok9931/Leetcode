class Solution {
public:
    void solve(vector<int>& candidates, int target, vector <vector <int>> &ans, vector <int> &comb, int index, int total){
        if(total == target){
            ans.push_back(comb);
            return;
        }
        if(total > target || index >= candidates.size()) return;
        for(int i=index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            comb.push_back(candidates[i]);
            solve(candidates, target, ans, comb, i + 1, total + candidates[i]);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <vector <int>> ans;
        vector <int> comb;
        solve(candidates, target, ans, comb, 0, 0);
        return ans;
    }
};
