#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    int res = r;
    while (l <= r) {
      int cap = (l + r) / 2;
      if (canFit(weights, days, cap)) {
        res = min(res, cap);
        r = cap - 1;
      } else {
        l = cap + 1;
      }
    }

    return res;
  }

  bool canFit(vector<int> &weights, int days, int cap) {
    int ship = 1;
    int curr_cap = cap;

    for (auto w : weights) {
      if (curr_cap - w < 0) {
        ship++;
        if (ship > days) {
          return false;
        }
        curr_cap = cap;
      }
      curr_cap -= w;
    }

    return true;
  }
};