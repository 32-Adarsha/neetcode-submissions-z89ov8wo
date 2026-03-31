
class Solution {
public:
  vector<pair<int, int>> movement = {{0, 1}, {1, 0}};
  int longestCommonSubsequence(string text1, string text2) {
    int t1Length = text1.length();
    int t2Length = text2.length();
    vector<vector<int>> grid(t1Length, vector<int>(t2Length, -1));
    for (int i = t1Length - 1; i >= 0; --i) {
      for (int j = t2Length - 1; j >= 0; --j) {
        int subSequnce = dfs({i, j}, grid, text1, text2);
        grid[i][j] = subSequnce;
      }
    }

    return grid[0][0];
  }

  int dfs(pair<int, int> point, vector<vector<int>> &grid, string text1,
          string text2) {

    if (point.first >= grid.size() || point.second >= grid[0].size()) {
      return 0;
    }

    if (grid[point.first][point.second] != -1) {
      return grid[point.first][point.second];
    }

    int subSequnce = 0;
    if (text1[point.first] == text2[point.second]) {
      subSequnce =
          1 + dfs({point.first + 1, point.second + 1}, grid, text1, text2);
    } else {
      for (auto move : movement) {
        subSequnce =
            max(subSequnce,
                dfs({point.first + move.first, point.second + move.second},
                    grid, text1, text2));
      }
    }

    grid[point.first][point.second] = subSequnce;
    return subSequnce;
  }
};

