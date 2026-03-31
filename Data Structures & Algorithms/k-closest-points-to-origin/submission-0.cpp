
struct Compare {
  bool operator()(const std::vector<int> &p1,
                  const std::vector<int> &p2) const {
    int dist1 = p1[0] * p1[0] + p1[1] * p1[1];
    int dist2 = p2[0] * p2[0] + p2[1] * p2[1];
    return dist1 > dist2; // Min heap: closest points first
  }
};

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                         int k) {
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        Compare>
        pq;
    for (int i = 0; i < points.size(); ++i) {
      pq.push(points[i]);
    }

    std::vector<std::vector<int>> result;
    while (!pq.empty() && k > 0) {
      std::vector<int> top = pq.top();
      result.push_back(top);
      pq.pop();
      k--;
    }

    return result;
  }
};