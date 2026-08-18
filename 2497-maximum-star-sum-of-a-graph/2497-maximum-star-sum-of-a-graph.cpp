class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans = INT_MIN;
        for (int i=0;i<n;i++) {
            vector<int> neighbors;
            for (int v:adj[i]) {
                if (vals[v] > 0)
                    neighbors.push_back(vals[v]);
            }
            sort(neighbors.rbegin(), neighbors.rend());
            int sum = vals[i];
            for (int j=0;j<min(k, (int)neighbors.size());j++) {
                sum += neighbors[j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
