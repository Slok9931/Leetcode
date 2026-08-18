class Solution {
private:
    bool dfs(int node,vector<int>& visit,vector<vector<int>>& adj,vector<int>& ans) {
        visit[node] = 1 ;
        for (int i : adj[node]) {
            if (!visit[i]) {
                if (dfs(i,visit,adj,ans)) return true ;
            }
            else if (visit[i] == 1) {
                return true ;
            }
        }
        ans.push_back(node) ;
        visit[node] = 2 ;
        return false ;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses ;
        vector<int> ans ;
        vector<vector<int>> adj(n);
        vector<int> visit(n, 0);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        } 
        for (int i=0 ; i<n ; i++) {
            if (!visit[i]) {
                if (dfs(i,visit,adj,ans)) return {} ;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
};
