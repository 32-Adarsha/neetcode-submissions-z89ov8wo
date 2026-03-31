#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<pair<int, int>> dp(nums.size(), make_pair(INT_MIN, INT_MAX));
    dp[nums.size() - 1] =
        make_pair(nums[nums.size() - 1], nums[nums.size() - 1]);
    int higestProdcut = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; --i) {
      dp[i].first = max(
          nums[i], max(nums[i] * dp[i + 1].first, nums[i] * dp[i + 1].second));
      dp[i].second = min(
          nums[i], min(nums[i] * dp[i + 1].first, nums[i] * dp[i + 1].second));

      higestProdcut = max(higestProdcut, dp[i].first);
    }
    return higestProdcut;
  }
};

