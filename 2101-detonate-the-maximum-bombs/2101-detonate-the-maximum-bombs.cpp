class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj, int n){
        vector<bool> vis(n, false);
        queue<int>q;
        q.push(node);
        vis[node] = true;
        int count = 1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i:adj[top]){
                if(!vis[i]){
                    vis[i] = true;
                    count++;
                    q.push(i);
                }
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                if (dist <= r1 * r1) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans, bfs(i,adj, n));
        return ans;
    }
};
