class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto &edge : relations) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            graph[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = time[i];
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                dp[v] = max(dp[v], dp[u] + time[v]);
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
