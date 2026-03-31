#include <exception>
#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result = {};
    std::set<int> unique;
    dfs(result, nums, 0, unique, {});
    return result;
  }

  void dfs(std::vector<std::vector<int>> &result, std::vector<int> &nums,
           int start, std::set<int> &unique, std::vector<int> temp) {
    if (temp.size() == nums.size()) {
      result.push_back(temp);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (unique.find(nums[i]) != unique.end())
        continue;
      temp.push_back(nums[i]);
      unique.insert(nums[i]);
      dfs(result, nums, i, unique, temp);
      unique.erase(nums[i]);
      temp.pop_back();
    }
  }
};

