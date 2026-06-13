#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;

public:
  vector<vector<int>> combine(int n, int k) {
    BackTrack(1, n, k, {});
    return result;
  }

  void BackTrack(int i, int n, int k, vector<int> comb) {
    if (comb.size() == k) {
      result.push_back(comb);
      return;
    }

    for (; i <= n; ++i) {
      comb.push_back(i);
      BackTrack(i + 1, n, k, comb);
      comb.pop_back();
    }
  }
};
