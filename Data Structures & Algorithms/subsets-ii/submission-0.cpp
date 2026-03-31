
class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::vector<std::vector<int>> result = {};
    std::sort(nums.begin(), nums.end());
    DFS(result, nums, 0, {});
    return result;
  }

  void DFS(std::vector<std::vector<int>> &result, std::vector<int> &nums,
           int start, std::vector<int> temp) {
    int i = start;
    result.push_back(temp);
    while (i < nums.size()) {
      temp.push_back(nums[i]);
      DFS(result, nums, i + 1, temp);
      temp.pop_back();
      i++;

      while (i < nums.size() & nums[i - 1] == nums[i]) {
        i++;
      }
    }
  }
};


