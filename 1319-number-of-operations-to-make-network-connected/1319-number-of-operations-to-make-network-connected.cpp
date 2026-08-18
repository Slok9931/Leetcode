class Solution {
public:
    void bfs(const vector<vector<int>> &adj, vector<int> &vis, int start) {
        queue<int> q;
        vis[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(adj, vis, i);
                components++;
            }
        }
        return components - 1;
    }
};
