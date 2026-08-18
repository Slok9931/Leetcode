class Solution {
public:
    void dfs(int node, unordered_map<int, bool> &vis, vector<vector<int>>&adj){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <vector <int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i != j) adj[i].push_back(j);
            }
        }
        int ans = 0;
        unordered_map<int, bool> vis;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans;
    }
};
