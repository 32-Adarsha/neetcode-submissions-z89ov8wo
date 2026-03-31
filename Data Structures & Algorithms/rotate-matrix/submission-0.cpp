#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    // NOTE: Two pass method
    int width = matrix[0].size() - 1;
    int height = matrix.size() - 1;
    for (int i = 0; i <= height / 2; ++i) {
      for (int j = 0; j <= width; ++j) {
        std::swap(matrix[i][j], matrix[height - i][j]);
      }
    }

    for (int i = 0; i <= height; ++i) {
      for (int j = 0; j <= i; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

