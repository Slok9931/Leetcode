class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto f:flights) adj[f[0]].push_back({f[1], f[2]});
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        pq.push({0, {src, 0}});
        dist[src][0] = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int cost = top.first, u = top.second.first, stops = top.second.second;
            if(u == dst) return cost;
            if(stops > k) continue;
            for(auto [v, w]:adj[u]){
                if (cost + w < dist[v][stops + 1]) {
                    dist[v][stops + 1] = cost + w;
                    pq.push({cost + w, {v, stops + 1}});
                }
            }
        }
        return -1;
    }
};
