class Solution {
private:
    bool dfs(int node, const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path) {
        vis[node] = path[node] = true;
        for (int i : adj[node]) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, path)) return true;
            } else if (path[i]) {
                return true;
            }
        }
        path[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto i : prerequisites) adj[i[1]].push_back(i[0]);
        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, path)) return false;
            }
        }
        return true;
    }
};
