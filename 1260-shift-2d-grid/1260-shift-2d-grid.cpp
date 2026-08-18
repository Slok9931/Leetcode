class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), index = 0;
        vector<int> v(m*n);
        k %= m*n;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++){
            v[index] = grid[i][j];
            index++;
        }
        reverse(v.begin(), v.end() - k);
        reverse(v.end() - k, v.end());
        reverse(v.begin(), v.end());
        vector<vector<int>> ans(m, vector<int>(n));
        index = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = v[index];
                index++;
            }
        }
        return ans;
    }
};
