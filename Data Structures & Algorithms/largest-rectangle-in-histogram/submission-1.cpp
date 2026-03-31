
struct Bars {
  int idx;
  int height;

  Bars(int idx, int height) : height(height), idx(idx) {}
};

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    int maxArea = 0;
    std::stack<Bars> s;
    for (int i = 0; i < heights.size(); ++i) {
      if (s.empty()) {
        s.push(Bars(i, heights[i]));
        continue;
      }

      if (s.top().height <= heights[i]) {
        s.push(Bars(i, heights[i]));
      } else {
        int last_idx = 0;
        while (!s.empty() && s.top().height > heights[i]) {
          int area = (i - s.top().idx) * s.top().height;
          maxArea = std::max(area, maxArea);
          last_idx = s.top().idx;
          s.pop();
        }
        s.push(Bars(last_idx, heights[i]));
      }
    }

    int last_idx = heights.size();
    while (!s.empty()) {
      int area = (last_idx - s.top().idx) * s.top().height;
      maxArea = std::max(area, maxArea);
      s.pop();
    }

    return maxArea;
  }
};

