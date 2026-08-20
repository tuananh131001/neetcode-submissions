class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int n = matrix[0].size();
        int r = matrix.size() * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target){
                return true;
            } else if (matrix[row][col] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return false;
        
    }
};
