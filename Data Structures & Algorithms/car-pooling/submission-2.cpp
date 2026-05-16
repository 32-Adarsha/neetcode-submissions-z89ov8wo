
struct Compare {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first > p2.first;
  }
};

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    sort(trips.begin(), trips.end(),
         [](auto t1, auto t2) { return t1[1] < t2[1]; });

    std::priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>
        Destination;
    int inside = 0;
    for (auto trip : trips) {
      while (!Destination.empty() && Destination.top().first <= trip[1]) {
        inside -= Destination.top().second;
        Destination.pop();
      }
      cout << inside + trip[0] << endl;
      if ((inside + trip[0]) > capacity)
        return false;
      Destination.push({trip[2], trip[0]});
      inside += trip[0];
    }

    return true;
  }
};

