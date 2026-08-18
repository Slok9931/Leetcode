class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top.first, r = top.second.first, c = top.second.second;
            if(d > dist[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int edge = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(edge, d);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};
