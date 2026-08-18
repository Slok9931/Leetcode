class Solution {
public:
    int solve(vector<vector<pair<int, int>>>&adj, int node, int k, int n){
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[node] = 0;
        pq.push({0, node});
        while(!pq.empty()){
            auto[d, u] = pq.top();
            pq.pop();
            for(auto[v, w]:adj[u]){
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({d + w, v});
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++) if(dist[i] <= k) count++;
        return count-1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int mini = INT_MAX, city;
        for(int i=0;i<n;i++){
            int x = solve(adj, i, k, n);
            if(x <= mini){
                mini = x;
                city = i; 
            }
        }
        return city;
    }
};
