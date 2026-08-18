class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / m;
            int col = mid % m;
            int val = matrix[row][col];

            if (val == target) return true;
            else if (val < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};
