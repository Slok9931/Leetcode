class Solution {
public:
    bool solve(int i, int j, int len, string word, vector<vector<char>>&board, int m, int n){
        if(len == word.size()) return true;
        if(i < 0 || i >= m || j< 0 || j >= n || board[i][j] != word[len]) return false;
        char temp = board[i][j];
        board[i][j] = '\0';
        if(solve(i+1, j, len+1, word, board, m, n) || solve(i-1, j, len+1, word, board, m, n) || solve(i, j+1, len+1, word, board, m, n) || solve(i, j-1, len+1, word, board, m, n)) return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(i, j, 0, word, board, m, n)) return true;
            }
        }
        return false;
    }
};
