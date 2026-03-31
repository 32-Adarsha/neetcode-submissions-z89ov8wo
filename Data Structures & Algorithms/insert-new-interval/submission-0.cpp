
class Solution {
public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                       std::vector<int> interval) {

    std::vector<std::vector<int>> result;
    for (int i = 0; i < intervals.size(); i++) {
      std::vector<int> point = intervals[i];
      if (interval[1] < point[0]) {
        result.push_back({interval});
        for (int j = i; j < intervals.size(); ++j) {
          result.push_back(intervals[j]);
        }
        return result;
      } else if (interval[0] > point[1]) {
        result.push_back(point);
        continue;
      } else {
        interval[0] = std::min(interval[0], point[0]);
        interval[1] = std::max(interval[1], point[1]);
      }
    }

    result.push_back(interval);
    return result;
  };
};
