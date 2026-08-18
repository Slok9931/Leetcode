class Solution {
public:
    void solve(int k, int n, vector<vector<int>>& ans, vector<int>& nums, int sum, int index, int count){
        if(count > k || sum > n) return;
        if(count == k && sum == n){
            ans.push_back(nums);
            return;
        }
        for(int i=index+1;i<10;i++){
            nums.push_back(i);
            sum += i;
            solve(k, n, ans, nums, sum, i, count+1);
            sum -= i;
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        int sum = 0;
        solve(k, n, ans, nums, sum, 0, 0);
        return ans;
    }
};
