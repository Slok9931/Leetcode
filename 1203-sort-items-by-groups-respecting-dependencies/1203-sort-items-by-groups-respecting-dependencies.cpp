class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }
        if (topo.size() != V)
            return {};

        return topo;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = m++;
        }
        vector<vector<int>> itemAdj(n);
        vector<vector<int>> groupAdj(m);
        for (int i = 0; i < n; i++) {
            for (int x : beforeItems[i]) {
                itemAdj[x].push_back(i);
                if (group[x] != group[i]) {
                    groupAdj[group[x]].push_back(group[i]);
                }
            }
        }
        vector<int> groupOrder = topoSort(m, groupAdj);
        if (groupOrder.empty())
            return {};
        vector<int> itemOrder = topoSort(n, itemAdj);
        if (itemOrder.empty())
            return {};
        vector<vector<int>> itemsInGroup(m);
        for (int item : itemOrder) {
            itemsInGroup[group[item]].push_back(item);
        }
        vector<int> ans;
        for (int g : groupOrder) {
            for (int item : itemsInGroup[g]) {
                ans.push_back(item);
            }
        }
        return ans;
    }
};