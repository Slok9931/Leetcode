class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<char>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = (int)stones.size();
        vector<vector<int>> adj(n);
        unordered_map<int, vector<int>> byRow;
        unordered_map<int, vector<int>> byCol;

        for (int i = 0; i < n; i++) {
            byRow[stones[i][0]].push_back(i);
            byCol[stones[i][1]].push_back(i);
        }
        auto connectGroup = [&](unordered_map<int, vector<int>>& mp) {
            for (auto &kv : mp) {
                auto &v = kv.second;
                for (int i = 1; i < (int)v.size(); i++) {
                    int a = v[i - 1], b = v[i];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
        };
        connectGroup(byRow);
        connectGroup(byCol);
        vector<char> vis(n, 0);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, adj, vis);
                components++;
            }
        }
        return n - components;
    }
};
