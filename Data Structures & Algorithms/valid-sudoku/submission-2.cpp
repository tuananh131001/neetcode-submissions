class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
           // hashset by row , cols , use map of int vs hashset
    unordered_map<int, unordered_set<int>> rowSet, colSet;
    // hashmap contains value as hashset use pair and hashset<int>
    map<pair<int,int>, unordered_set<int>> areaSet;
    
    for (int c = 0; c < board.size(); c++) { // cols
        for (int r = 0 ; r < board[c].size(); r++) { // row
          // get the outter of the area
          pair<int, int> areaPos = { c / 3, r / 3};

          if (board[c][r] == '.') continue;

          // check if the value is exists in all conditions
          if (rowSet[r].count(board[c][r]) || colSet[c].count(board[c][r]) || areaSet[areaPos].count(board[c][r])) {
            return false;
          }
          
          colSet[c].insert(board[c][r]);
          rowSet[r].insert(board[c][r]);
          areaSet[areaPos].insert(board[c][r]);
      }
    }
    return true;

    }
};
