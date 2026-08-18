class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<unordered_set<int>> adj(n);
        for(auto i:roads){
            degree[i[0]]++;
            degree[i[1]]++;
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = degree[i] + degree[j];
                if(adj[i].find(j) != adj[i].end()) sum--;
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
