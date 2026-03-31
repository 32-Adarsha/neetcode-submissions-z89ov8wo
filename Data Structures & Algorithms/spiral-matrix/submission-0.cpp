
class Solution {
private:
  std::vector<int> result;
  std::pair<int, int> getInOrder(std::vector<std::vector<int>> &matrix,
                                 std::pair<int, int> movement,
                                 std::pair<int, int> point, int iteration) {
    // NOTE: Start
    for (int i = 0; i < iteration; ++i) {
      point = {point.first + movement.first, point.second + movement.second};
      result.push_back(matrix[point.first][point.second]);
    }
    return point;
  }

public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matirx) {
    int width = matirx[0].size();
    int height = matirx.size();

    std::pair<int, int> s_point = {0, -1};
    while (width > 0 && height > 0) {
      // NOTE: Right Movement
      if (width > 0 && height > 0) {
        s_point = getInOrder(matirx, {0, 1}, s_point, width);
      }

      height -= 1;
      // NOTE: Down Movement
      if (height > 0 && width > 0) {
        s_point = getInOrder(matirx, {1, 0}, s_point, height);
      }

      width -= 1;
      // NOTE: Left Movement
      if (width > 0 && height > 0) {
        s_point = getInOrder(matirx, {0, -1}, s_point, width);
      }

      height -= 1;

      if (height > 0 && width > 0) {
        s_point = getInOrder(matirx, {-1, 0}, s_point, height);
      }

      width -= 1;
    }

    return result;
  }
};

;

