class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for(int s = 0; s < n; s++) {
            if(color[s] != 0) continue;
            queue<int> q;
            q.push(s);
            color[s] = 1;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : graph[u]) {
                    if(color[v] == 0) {
                        color[v] = (color[u] == 1 ? 2 : 1);
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
