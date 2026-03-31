
class Solution {
private:
  map<pair<int, int>, int> dp;

public:
  int maxCoins(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    return subProblem(1, nums.size() - 2, nums);
  }

  int subProblem(int left, int right, vector<int> &nums) {
    if (left == right) {
      return nums[left - 1] * nums[left] * nums[left + 1];
    }

    auto it = dp.find({left, right});
    if (it != dp.end()) {
      return it->second;
    }
    int maxValue = 0;
    for (int i = left; i <= right; ++i) {
      int value = nums[left - 1] * nums[i] * nums[right + 1];
      int leftValue = subProblem(left, i - 1, nums);
      int rightValue = subProblem(i + 1, right, nums);
      maxValue = max(maxValue, leftValue + value + rightValue);
    }

    dp[{left, right}] = maxValue;
    return maxValue;
  }
};

