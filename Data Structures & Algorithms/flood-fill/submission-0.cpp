class Solution {
    int rows, cols;
private:
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited, int originColor, int targetColor) {
        // Base case: when row is out-of-bound
        if (row < 0 || row >= this->rows || col < 0 || col >= this->cols) {
            return;
        }
        if (visited[row][col] || grid[row][col] != originColor) {
            return;
        }

        visited[row][col] = true;
        // Choice
        // Change the color of current pixel to target color when the color is same as originColor
        grid[row][col] = targetColor;

        vector<pair<int,int>> directions = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        for (auto& dir: directions){
            dfs(grid, row + dir.first, col + dir.second, visited, originColor, targetColor);
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->rows = image.size();
        this->cols = image[0].size();
        vector<vector<bool>> visited(this->rows, vector<bool>(this->cols, false));
        int chosenColor = image[sr][sc];
        dfs(image, sr, sc, visited, chosenColor, color);
        return image;
    }
};