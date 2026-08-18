class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int s = 0, e = mat[0].size() - 1;
        while(s <= e){
            int mid = s + (e-s)/2, row = 0;
            for(int i=1;i<mat.size();i++){
                if(mat[i][mid] > mat[row][mid]) row = i;
            }
            int left = (mid >= 1) ? mat[row][mid-1] : -1;
            int right = (mid < mat[0].size()-1) ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
            else if(mat[row][mid] < right) s = mid + 1;
            else e = mid - 1;
        }
        return {-1, -1};
    }
};
