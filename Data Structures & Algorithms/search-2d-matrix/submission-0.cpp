class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0;
        int bot = ROWS - 1;
        while (top <= bot) {
            int rowMid = top + (bot - top) / 2;
            if (target > matrix[rowMid][COLS - 1]) {
                top = rowMid + 1;
            } else if (target < matrix[rowMid][0]) {
                bot = rowMid - 1;
            } else {
                break;
            }
        }

        if (!(top <= bot)) {
            return false;
        }

        int row = (top + bot) / 2; //??
        int l = 0;
        int r = COLS - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[row][m] == target) {
                return true;
            } else if (matrix[row][m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
        
    }
};
