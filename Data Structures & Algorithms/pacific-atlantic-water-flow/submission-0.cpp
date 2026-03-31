
class Solution {

public:
  vector<pair<int, int>> movement = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int ROWS = heights.size();
    int COLS = heights[0].size();

    vector<vector<int>> pReach(ROWS, vector<int>(COLS, false));
    vector<vector<int>> aReach(ROWS, vector<int>(COLS, false));

    for (int i = 0; i < ROWS; ++i) {
      dfs(heights, {i, 0}, pReach);
      dfs(heights, {i, COLS - 1}, aReach);
    }

    for (int j = 0; j < COLS; ++j) {
      dfs(heights, {0, j}, pReach);
      dfs(heights, {ROWS - 1, j}, aReach);
    }

    vector<vector<int>> result;

    for (int i = 0; i < ROWS; ++i) {
      for (int j = 0; j < COLS; ++j) {
        if (aReach[i][j] && pReach[i][j])
          result.push_back({i, j});
      }
    }

    return result;
  }

  void dfs(vector<vector<int>> &heights, pair<int, int> point,
           vector<vector<int>> &reach) {
    reach[point.first][point.second] = true;

    for (auto move : movement) {
      pair<int, int> newPoint = {point.first + move.first,
                                 point.second + move.second};

      if (newPoint.first < 0 || newPoint.second < 0 ||
          newPoint.first >= heights.size() ||
          newPoint.second >= heights[0].size() ||
          (heights[newPoint.first][newPoint.second] <
           heights[point.first][point.second]) ||
          reach[newPoint.first][newPoint.second]) {

        continue;
      }

      dfs(heights, newPoint, reach);
    }
  }
};

