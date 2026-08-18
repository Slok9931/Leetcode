class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &states, int node){
        states[node] = 1;
        for(auto i:graph[node]){
            if(states[i] == 1) return true;
            if(states[i] == 0){
                if(dfs(graph, states, i)) return true;
            }
        }
        states[node] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> states(n, 0), ans;
        for(int i=0;i<n;i++){
            if(states[i] == 0) dfs(graph, states, i);
        }
        for(int i=0;i<n;i++){
            if(states[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};
