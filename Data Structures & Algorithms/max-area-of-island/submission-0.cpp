
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    vector<pair<int, int>> n = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int area = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          int tempArea = 1;
          queue<pair<int, int>> q;
          grid[i][j] = 0;
          q.push({i, j});
          while (!q.empty()) {
            pair<int, int> point = q.front();
            q.pop();
            for (auto p : n) {
              pair<int, int> nPoint = {point.first + p.first,
                                       point.second + p.second};
              if (nPoint.first >= 0 && nPoint.first < grid.size() &&
                  nPoint.second >= 0 && nPoint.second < grid[0].size() &&
                  grid[nPoint.first][nPoint.second] ==
                      1) {  // Check if it's land!
                tempArea++; // Increment here when we find land
                q.push(nPoint);
                grid[nPoint.first][nPoint.second] = 0;
              }
            }
          }
          area = max(area, tempArea);
        }
      }
    }
    return area;
  }
};