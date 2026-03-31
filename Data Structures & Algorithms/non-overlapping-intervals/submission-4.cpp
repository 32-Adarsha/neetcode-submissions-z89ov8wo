
class Solution {
public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](std::vector<int> first, std::vector<int> second) {
                return first[0] < second[0];
              });
    int count = 0;
    std::vector<int> lastPair = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
      if (lastPair[1] <= intervals[i][0]) {
        lastPair = intervals[i];
      } else {
           std::cout << lastPair[0] << " " << lastPair[1] << " , " << intervals[i][0] <<" " <<intervals[i][1] << std::endl;
        count++;
        if (intervals[i][1] < lastPair[1] ) {
          lastPair = intervals[i];
        }
      }
    }

    return count;
  }
};

