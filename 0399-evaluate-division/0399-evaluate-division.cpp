class Solution {
public:
    void dfs(string u, string &v, unordered_map<string, unordered_map<string, double>> &adj, unordered_set<string> &vis, double &res, double temp){
        if(vis.find(u) != vis.end()) return;
        vis.insert(u);
        if(u == v){
            res = temp;
            return;
        }
        for(auto i:adj[u]) dfs(i.first, v, adj, vis, res, temp*i.second);
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        vector<double> ans;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        for(auto q:queries){
            if(adj.find(q[0]) == adj.end() || adj.find(q[1]) == adj.end()) ans.push_back(-1.0);
            else{
                unordered_set<string> vis;
                double res = -1, temp = 1.0;
                dfs(q[0], q[1], adj, vis, res, temp);
                ans.push_back(res);
            }
        }
        return ans;
    }
};
