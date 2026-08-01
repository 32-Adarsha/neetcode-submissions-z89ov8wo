#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }

    int result = 0;
    for (auto [key, value] : count) {
      int total_pair = ((value - 1) * value) / 2;
      result += total_pair;
    }

    return result;
  }
};

