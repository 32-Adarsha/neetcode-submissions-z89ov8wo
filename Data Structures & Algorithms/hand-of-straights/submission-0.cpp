
class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    sort(hand.begin(), hand.end());

    // NOTE: can't be be fit in groupSize size slot
    if (hand.size() % groupSize != 0)
      return false;

    vector<vector<int>> slots(hand.size() / groupSize, vector<int>{});
    for (int i = 0; i < hand.size(); ++i) {
      int j = 0;
      while (j < slots.size()) {
        vector<int> &slot = slots[j];
        if (slot.empty()) {
          slot.push_back(hand[i]);
          break;
        }
        if (hand[i] - slot[slot.size() - 1] == 1 &&
            (slot.size() + 1 <= groupSize)) {
          slot.push_back(hand[i]);
          break;
        }
        j++;
      }
      if (j >= slots.size()) {
        return false;
      }
    }

    return true;
  }
};

