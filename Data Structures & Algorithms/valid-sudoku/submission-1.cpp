class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> colSet, rowSet;
        map<pair<int, int>, unordered_set<char>>  areaSet;

        for (int i = 0; i < board.size(); i++) { // row
            for (int j = 0; j < board[i].size(); j++) { // col
                // check if dup
                char value  = board[i][j];
                pair<int, int> areaPos = {i / 3, j / 3};

                if (value == '.') {
                    continue;
                }

                if (colSet[j].count(value) || rowSet[i].count(value) || areaSet[areaPos].count(value)) { // found an duplicates
                    return false;
                }

                colSet[j].insert(board[i][j]); // col, value
                rowSet[i].insert(board[i][j]); // row, value
                areaSet[areaPos].insert(board[i][j]);
            }
        }

        return true;
    }
};
