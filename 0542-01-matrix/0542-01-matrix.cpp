class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector <vector <int>> ans(m, vector<int> (n, 0));
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int r = top.first.first, c = top.first.second, d = top.second;
            ans[r][c] = d;
            if(r-1 >= 0 && !vis[r-1][c]){
                vis[r-1][c] = true;
                q.push({{r-1, c}, d+1});
            }
            if(r+1 < m && !vis[r+1][c]){
                vis[r+1][c] = true;
                q.push({{r+1, c}, d+1});
            }
            if(c-1 >= 0 && !vis[r][c-1]){
                vis[r][c-1] = true;
                q.push({{r, c-1}, d+1});
            }
            if(c+1 < n && !vis[r][c+1]){
                vis[r][c+1] = true;
                q.push({{r, c+1}, d+1});
            }
        }
        return ans;
    }
};
