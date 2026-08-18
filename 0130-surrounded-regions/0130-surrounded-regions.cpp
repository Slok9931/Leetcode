class Solution {
public:
    int row, col;
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &vis){
        if(i >= row || i < 0 || j >= col || j < 0 || vis[i][j] || board[i][j] == 'X') return;
        vis[i][j] = true;
        dfs(i-1, j, board, vis);
        dfs(i+1, j, board, vis);
        dfs(i, j-1, board, vis);
        dfs(i, j+1, board, vis);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        row = m, col = n;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, board, vis);
            if(board[i][n-1] == 'O' && !vis[i][n-1]) dfs(i, n-1, board, vis);
        }
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O' && !vis[0][j]) dfs(0, j, board, vis);
            if(board[m-1][j] == 'O' && !vis[m-1][j]) dfs(m-1, j, board, vis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
