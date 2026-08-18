class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <pair <int, int>> freq;
        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1) count++;
            }
            freq.push_back({count, i});
        }
        sort(freq.begin(), freq.end());
        vector <int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
