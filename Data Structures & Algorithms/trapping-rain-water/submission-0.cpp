#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int trap(std::vector<int> &height) {
    std::vector<int> rightMax(height.size(), 0);
    int max = 0;
    int result = 0;
    for (int i = height.size() - 1; i >= 0; --i) {
      rightMax[i] = max;
      max = std::max(max, height[i]);
    }
    max = 0;
    for (int i = 0; i < height.size(); ++i) {
      int temp = (std::min(max, rightMax[i]) - height[i]);
      if (temp > 0)
        result += temp;
      max = std::max(max, height[i]);
    }

    return result;
  }
};

