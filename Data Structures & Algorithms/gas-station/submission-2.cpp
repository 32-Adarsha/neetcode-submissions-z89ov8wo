
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int l = 0;
    int found = false;
    int index = -1;
    int lNegativeSum = 0;
    int carry = 0;
    while (l < gas.size()) {
      if (gas[l] >= cost[l] && index == -1) {
        index = l;
      }

      if ((carry + gas[l] - cost[l]) < 0) {
        lNegativeSum += carry + gas[l] - cost[l];
        index = -1;
        carry = 0;
      } else {
        carry = (carry + gas[l] - cost[l]);
      }

      l++;
    }

    if (index != -1 && (carry + lNegativeSum) >= 0) {
      return index;
    } else {
      return -1;
    }
  }
};

