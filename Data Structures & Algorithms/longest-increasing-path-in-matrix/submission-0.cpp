
class Solution {
  vector<pair<int, int>> Directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  map<pair<int, int>, int> MeMo;
  int highest = 0;

public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {

    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        dfs({i, j}, matrix);
      }
    }

    return highest;
  }

  int dfs(pair<int, int> index, vector<vector<int>> &matrix) {
    int maxDir = 1;

    auto it = MeMo.find(index);

    if (it != MeMo.end()) {
      return it->second;
    }

    for (auto direction : Directions) {
      int x = direction.first + index.first;
      int y = direction.second + index.second;

      if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
          matrix[x][y] > matrix[index.first][index.second]) {
        maxDir = max(maxDir, dfs({x, y}, matrix) + 1);
      }
    }

    MeMo[{index.first, index.second}] = maxDir;
    highest = max(highest, maxDir);
    return maxDir;
  }
};

