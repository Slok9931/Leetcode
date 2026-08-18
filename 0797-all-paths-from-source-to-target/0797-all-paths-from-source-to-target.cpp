class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> &path, int node){
        path.push_back(node);
        if(node == n-1) ans.push_back(path);
        else for(auto i:graph[node]) dfs(graph, ans, path, i);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> path;
        vector<vector<int>> ans;
        dfs(graph, ans, path, 0);
        return ans;
    }
};
