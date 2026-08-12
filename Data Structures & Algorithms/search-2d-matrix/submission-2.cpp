class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int COLS = matrix.size();
        int ROWS = matrix[0].size();

        int top = 0, bot = COLS - 1;
        while (top <= bot) {
            int midIdx = top + (bot - top) / 2;
            if (target > matrix[midIdx][ROWS - 1]) {
                top = midIdx + 1; 
            } else if (target < matrix[midIdx][0]) {
                // [[0, 2, 4], [5, 7, 9]] // target = 2 , first 2nd row is 5
                bot = midIdx - 1;
            } else {
                break;
            }
        }

        if (!(top <= bot)) {
            return false;
        }

        int row = (top + bot) / 2; // ??
        int l = 0, r = ROWS - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[row][m] == target) {
                return true;
            }
            // [0,  2 , 4 , 5] target 2 , mid = 4
            else if (matrix[row][m] < target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};
