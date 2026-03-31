
class Solution {
public:
  vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  void solve(vector<vector<char>> &board) {

    int row = board.size();
    int col = board[0].size();

    // NOTE: keeping col constat at 0
    for (int i = 0; i < row; ++i) {
      if (board[i][0] == 'O') {
        dfs(board, {i, 0});
      }
    }

    // NOTE:  keeping col constant at col -1
    for (int i = 0; i < row; ++i) {
      if (board[i][col - 1] == 'O') {
        dfs(board, {i, col-1});
      }
    }

    // NOTE: keeping row constant at 0
    for (int i = 0; i < col; ++i) {
      if (board[0][i] == 'O') {
        dfs(board, {0, i});
      }
    }

    // NOTE: keeping row conatant at row -1
    for (int i = 0; i < col; ++i) {
      if (board[row - 1][i] == 'O') {
        dfs(board, {row - 1 , i});
      }
    }

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == 'a') {
          board[i][j] = 'O';
        }
      }
    }


  }

  void dfs(vector<vector<char>> &board, pair<int, int> point) {
    board[point.first][point.second] = 'a';
    
    for (auto [dx, dy] : direction) {
      int x = point.first + dx;
      int y = point.second + dy;

      if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() &&
          board[x][y] == 'O') {
        dfs(board, {x, y});
      }
    }
  }
};