class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis,unordered_map<int,int>&mp,int dist){
        vis[node]=1;
        mp[node]=dist;
        for(auto &it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,adj,vis,mp,dist+1);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,vector<int>>adj;
        int n=edges.size();
        vector<int>vis1(n,0);
        vector<int>vis2(n,0);
        for(int i=0;i<n;i++){
            if(edges[i]==-1) continue;
            int u=i;
            int v=edges[i];

            adj[u].push_back(v);
        }
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        dfs(node1,adj,vis1,mp1,0);
        dfs(node2,adj,vis2,mp2,0);

        int result = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (mp1.count(i) && mp2.count(i)) {
                int maxDist = max(mp1[i], mp2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                } else if (maxDist == minDist && i < result) {
                    result = i;
                }
            }
        }

        return result;
    }
};
