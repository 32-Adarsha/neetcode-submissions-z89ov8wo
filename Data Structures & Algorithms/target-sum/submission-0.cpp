
class Solution {
public:
  map<pair<int, int>, int> ways;
  int findTargetSumWays(vector<int> &nums, int target) {
    return dfs(1, 0 + nums[0], target, nums) +
           dfs(1, 0 - nums[0], target, nums);
  }

  int dfs(int index, int currSum, int target, vector<int> &nums) {
    if (index >= nums.size()) {
      return (currSum == target) ? 1 : 0;
    }

    auto it = ways.find({index, currSum});
    if (it != ways.end()) {
      return it->second;
    }

    ways[{index, currSum}] +=
        dfs(index + 1, currSum + nums[index], target, nums);
    ways[{index, currSum}] +=
        dfs(index + 1, currSum - nums[index], target, nums);

    return ways[{index, currSum}];
  }
};

