class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;
        
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            
            for (auto &d : dir) {
                int nrow = row + d[0], ncol = col + d[1];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == oldColor) {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};
