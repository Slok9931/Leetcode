class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        while(top < bottom){
            for(int col=0;col<matrix.size();col++){
                swap(matrix[top][col], matrix[bottom][col]);
            }
            top++;
            bottom--;
        }
        for(int row=0;row<matrix.size();row++){
            for(int col=row+1;col<matrix.size();col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};
