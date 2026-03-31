
class Solution {
public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    int max_value = 0;
    for (int pile : piles) {
      max_value = std::max(pile, max_value);
    }

    int left = 1;
    int right = max_value;
    int min_speed = 0;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (canFinish(piles, mid, h)) {
        min_speed = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return min_speed;
  }

  bool canFinish(std::vector<int> &piles, int speed, int h) {
    int time = 0;
    for (int i = 0; i < piles.size(); ++i) {
      time += (piles[i] + speed - 1) / speed;
    }

    if (time <= h) {
      return true;
    } else {
      return false;
    }
  }
};

