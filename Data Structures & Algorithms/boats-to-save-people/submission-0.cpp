
class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    unordered_map<int, int> hash = {};
    int boat = 0;
    for (int i = 0; i < people.size(); ++i) {
      int otherpair = limit - people[i];
      auto it = hash.find(otherpair);

      if (it != hash.end() && it->second > 0) {
        it->second = it->second - 1;
        boat++;
      } else {
        hash[people[i]]++;
      }
    }

    vector<int> allUnmatchedValue = {};
    for (pair<int, int> p : hash) {
      if (p.second > 0) {
        while (p.second > 0) {
          allUnmatchedValue.push_back(p.first);
          p.second--;
        }
      }
    }

    sort(allUnmatchedValue.begin(), allUnmatchedValue.end());

    int left = 0;
    int right = allUnmatchedValue.size() - 1;

    while (left <= right) {
      int s = allUnmatchedValue[left];
      if (left != right) {
        s = allUnmatchedValue[left] + allUnmatchedValue[right];
      }
      if (s <= limit) {
        left++;
        right--;
      } else {
        right--;
      }
      boat++;
    }

    return boat;
  }
};

