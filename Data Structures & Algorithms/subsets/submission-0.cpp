
class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> result = {};
    dfs(result, nums, 0, {});
    return result;
  }

  void dfs(std::vector<std::vector<int>> &r, std::vector<int> &nums, int start,
           std::vector<int> temp) {

    r.push_back(temp);
    for (int i = start; i < nums.size(); ++i) {
      temp.push_back(nums[i]);
      dfs(r, nums, i + 1, temp);
      temp.pop_back();
    }
  }
};


