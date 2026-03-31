
class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int fresh = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          fresh++;
        }
      }
    }


    if(fresh == 0) return 0;

  

    int time = -1;
    int count_fresh = 0;
    while (!q.empty()) {
      time++;
      int s = q.size();
      for (int i = 0; i < s; ++i) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : direction) {
          int newx = x + dx;
          int newy = y + dy;
          if (newx >= 0 && newx < grid.size() && newy >= 0 &&
              newy < grid[0].size() && grid[newx][newy] == 1) {
            grid[newx][newy] = 2;
            q.push({newx, newy});
            count_fresh++;
          }
        }
      }
    }

    if (count_fresh == fresh){
      return time;
    }
    return -1;
  }
};