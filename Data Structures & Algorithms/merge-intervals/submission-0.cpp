
class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.size() <= 1)
      return intervals;
    std::vector<std::vector<int>> result;
    std::sort(intervals.begin(), intervals.end(),
              [](std::vector<int> first, std::vector<int> second) {
                return first[0] < second[0];
              });
    // NOTE: Assuming that the length is atleast 1
    std::vector<int> lastPair = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
      if (lastPair[1] < intervals[i][0]) {
        result.push_back(lastPair);
        lastPair = intervals[i];
      } else {
        lastPair[0] = std::min(lastPair[0], intervals[i][0]);
        lastPair[1] = std::max(lastPair[1], intervals[i][1]);
      }
    }

    result.push_back(lastPair);
    return result;
  }
};

