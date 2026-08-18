class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        int dr[] = {-1, -1, 0, -1, 1, 1, 0, 1};
        int dc[] = {0, -1, 1, 1, 0, -1, -1, 1};
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int d = top.first, r = top.second.first, c = top.second.second;
            for(int i=0;i<8;i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && d + 1 < dist[nr][nc]){
                    dist[nr][nc] = d + 1;
                    if(nr == n-1 && nc == n-1) return d + 1;
                    q.push({d+1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
