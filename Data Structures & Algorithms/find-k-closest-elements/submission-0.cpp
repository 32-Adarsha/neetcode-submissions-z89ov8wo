
class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    deque<int> dq;
    for (int i = 0; i < arr.size(); ++i) {
      if (dq.empty() || dq.size() < k) {
        dq.push_back(arr[i]);
        continue;
      }

      int dist1 = abs(dq.front() - x);
      int dist2 = abs(arr[i] - x);

      if (dist2 < dist1) {
        dq.pop_front();
        dq.push_back(arr[i]);
      }
    }

    vector<int> result;
    for (auto value : dq) {
      result.push_back(value);
    }

    return result;
  }
};

