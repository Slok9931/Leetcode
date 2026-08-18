class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv]) parent[pu] = pv;
            else if (rank[pu] > rank[pv]) parent[pv] = pu;
            else { parent[pv] = pu; rank[pu]++; }
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailMap;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailMap.find(email) == emailMap.end()) {
                    emailMap[email] = i;
                } else {
                    ds.unionByRank(i, emailMap[email]);
                }
            }
        }
        vector<string> merged[n];
        for (auto it : emailMap) {
            int root = ds.findUPar(it.second);
            merged[root].push_back(it.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), merged[i].begin(), merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};
