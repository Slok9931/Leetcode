class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for(auto &road:roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<int> dp(n);
        vector<long long> dist(n, LLONG_MAX);
        pq.push({0, 0});
        dp[0] = 1;
        while(!pq.empty()){
            auto [w, node] = pq.top();
            pq.pop();
            if(w > dist[node]) continue;
            for(auto v:adj[node]) {
                if(w + v.second < dist[v.first]){
                    dist[v.first] = w + v.second;
                    dp[v.first] = dp[node];
                    pq.push({dist[v.first], v.first});
                }
                else if(w + v.second == dist[v.first]) dp[v.first] = (dp[v.first] + dp[node]) % MOD;
            }
        }
        return dp[n-1];
    }
};
