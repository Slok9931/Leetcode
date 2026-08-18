class Solution {
public:
    long long getKey(int u, int v) {
        if (u > v) swap(u, v);
        return (1LL * u << 32) | v;
    }
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n+1, 0);
        unordered_set<long long> st;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            degree[u]++;
            degree[v]++;
            st.insert(getKey(u, v));
        }
        vector<int> odd;
        for (int i=1;i<=n;i++) {
            if (degree[i] % 2)
                odd.push_back(i);
        }
        if (odd.size() == 0)
            return true;
        if (odd.size() == 2) {
            int x = odd[0], y = odd[1];
            if (!st.count(getKey(x, y)))
                return true;
            for (int v=1;v<=n;v++) {
                if (v != x && v != y && !st.count(getKey(x, v)) && !st.count(getKey(y, v))) return true;
            }
            return false;
        }
        if (odd.size() == 4) {
            int a = odd[0], b = odd[1];
            int c = odd[2], d = odd[3];
            return (!st.count(getKey(a, b)) && !st.count(getKey(c, d))) || (!st.count(getKey(a, c)) && !st.count(getKey(b, d))) || (!st.count(getKey(a, d)) && !st.count(getKey(b, c)));
        }
        return false;
    }
};
