class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector <vector <int>> adj(n);
        for(auto i:edges){
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int, bool> vis;
        queue <int> q;
        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == destination) return true;
            for(auto i:adj[front]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};
