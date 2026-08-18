class Solution {
public:
    vector<vector<int>> tree;
    vector<int> subtreeSize;
    int n;
    long long maxScore = 0;
    int count = 0;
    int dfs(int node) {
        int size = 1;
        for (int child : tree[node]) {
            size += dfs(child);
        }
        subtreeSize[node] = size;
        return size;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        tree.resize(n);
        subtreeSize.resize(n);
        for (int i = 1; i < n; i++) {
            tree[parents[i]].push_back(i);
        }
        dfs(0);
        for (int i = 0; i < n; i++) {
            long long score = 1;
            int remaining = n - subtreeSize[i];
            if (remaining > 0)
                score *= remaining;
            for (int child : tree[i]) {
                score *= subtreeSize[child];
            }
            if (score > maxScore) {
                maxScore = score;
                count = 1;
            } else if (score == maxScore) {
                count++;
            }
        }
        return count;
    }
};
