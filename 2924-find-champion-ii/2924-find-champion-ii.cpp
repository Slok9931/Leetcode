class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for(auto i:edges) inDegree[i[1]]++;
        int count = 0;
        for(int i:inDegree) if(!i) count++;
        if(count > 1) return -1;
        else {
            for(int i=0;i<n;i++) if(!inDegree[i]) return i;
        }
        return -1;
    }
};
