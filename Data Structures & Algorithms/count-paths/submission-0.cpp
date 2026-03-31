
class Solution {
public:
  vector<pair<int, int>> movement = {{0, 1}, {1, 0}};
  int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int path = dfs({i, j}, m, n, grid);
        grid[i][j] = path;
      }
    }
    return grid[0][0];
  }

  int dfs(pair<int, int> point, int m, int n, vector<vector<int>> &grid) {
    if (point.first == m - 1 && point.second == n - 1) {
      return 1;
    }

    if (grid[point.first][point.second] != 0) {
      return grid[point.first][point.second];
    }

    int num_path = 0;
    for (auto move : movement) {
      pair<int, int> next_point = {point.first + move.first,
                                   point.second + move.second};
      if (next_point.first >= 0 && next_point.first < m &&
          next_point.second >= 0 && next_point.second < n) {
        num_path += dfs(next_point, m, n, grid);
      }
    }

    grid[point.first][point.second] = num_path;
    return num_path;
  }
};
