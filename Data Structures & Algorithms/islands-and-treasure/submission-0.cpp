
class Solution {
public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {

        // NOTE : gird [i][j] == 0 then we find the treasuer
        if (grid[i][j] == 0) {

          // INIT: temp that will only live till if last
          queue<pair<int, int>> q;
          map<pair<int, int>, bool> visited;
          int distance = 0;

          // PUSH: push the curren point to the q to start dfs
          q.push({i, j});

          // START: dfs to explore all the pace it can reach
          while (!q.empty()) {

            // CAL: the size
            int s = q.size();

            // increment distance
            distance++;

            // loop all the  nth childeren form 0
            for (int k = 0; k < s; ++k) {
              auto point = q.front();
              q.pop();

              for (auto dir : direction) {
                int x = point.first + dir.first;
                int y = point.second + dir.second;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                    grid[x][y] != 0 && grid[x][y] != -1 &&
                    visited.find({x, y}) == visited.end()) {
                  grid[x][y] = min(grid[x][y], distance);
                  visited[{x, y}] = 0;
                  q.push({x, y});
                }
              }
            }
          }
        }
      }
    }
  }
};