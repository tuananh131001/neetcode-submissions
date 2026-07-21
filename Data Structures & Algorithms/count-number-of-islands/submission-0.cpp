class Solution {
    int rows, cols;
    void dfs(vector<vector<char>>& grid, int row, int col) {
            if (row < 0 || row >= this->rows || col < 0 || col >= cols || grid[row][col] == '0') {
                return;
            }

            // choices
            grid[row][col] = '0';

            vector<pair<int, int>> directions = {
                {1,0}, {-1, 0}, {0,-1}, {0,1}
            };

            for (auto& dir : directions) {
                dfs(grid, row + dir.first, col + dir.second);
            }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        int res = 0;
        for (int i = 0 ; i < this->rows; i++) {
            for (int y = 0; y < this->cols; y++) {
                if (grid[i][y] == '1') {
                    res++;
                    dfs(grid,i ,y);
                }
            }
        }
        return res;
    }
};
