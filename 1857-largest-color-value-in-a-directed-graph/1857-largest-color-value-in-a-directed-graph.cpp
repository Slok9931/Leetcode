class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
         
        // first topological sort to check cyclic or not ...
        int n = colors.size();
        vector<vector<int>>adjList(n);
        vector<vector<int>> dp(n, vector<int>(26, 0));
        int res = 0;
        vector<int>deg(n,0);
        for(auto e:edges){
            int f = e[0];
            int s = e[1];
            adjList[f].push_back(s);
            deg[s]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i] == 0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);

            int coloridx = colors[t] - 'a';
            dp[t][coloridx]++;
            res = max(res,dp[t][coloridx]);

            for(int i=0;i<adjList[t].size();i++){
                for (int c=0; c<26;c++) {
                    dp[adjList[t][i]][c] = max(dp[adjList[t][i]][c], dp[t][c]);
                }
                deg[adjList[t][i]]--;
                if(deg[adjList[t][i]] == 0) q.push(adjList[t][i]);
            }
        }
        if(ans.size()!=n) return -1;

        return res;
    }
};
