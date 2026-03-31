#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
private:
  bool checkExistance(std::unordered_map<int, std::set<char>> &hash, int i,
                      char c) {
    if (hash.find(i) == hash.end()) {
      hash[i] = {};
    }
    if (hash[i].find(c) != hash[i].end()) {
      return false;
    } else {
      hash[i].insert(c);
    }
    return true;
  }

public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::unordered_map<int, std::set<char>> row;
    std::unordered_map<int, std::set<char>> col;
    std::unordered_map<int, std::set<char>> subBoard;

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == '.')
          continue;

        // NOTE: ROW
        if (!(checkExistance(row, i, board[i][j])))
          return false;
        // NOTE: Col
        if (!(checkExistance(col, j, board[i][j])))
          return false;
        // NOTE: SubBoard

        int boardPlace = ((i / 3) * 3 + (j / 3));
        if (!(checkExistance(subBoard, boardPlace, board[i][j])))
          return false;
      }
    }

    return true;
  }
};