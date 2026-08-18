class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1, 0);
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        for (auto e : edges) {
            int u = e[0], v = e[1];
            degree[u]++;
            degree[v]++;
            adj[u][v] = true;
            adj[v][u] = true;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!adj[i][j]) continue;
                for (int k = j + 1; k <= n; k++) {
                    if (adj[i][k] && adj[j][k]) {
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
