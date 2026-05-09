
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {};
    set<int> UsedIndex;
    backtracking(nums, 0, {}, result, UsedIndex);
    return result;
  }

  void backtracking(vector<int> &nums, int depth, vector<int> temp,
                    vector<vector<int>> &result, set<int> UsedIndex) {
    if (depth >= nums.size()) {
      result.push_back(temp);
      return;
    }

    int i = 0;

    while (i < nums.size()) {

      if (UsedIndex.find(i) != UsedIndex.end()) {
        i++;
        continue;
      }

      temp.push_back(nums[i]);
      UsedIndex.insert(i);

      backtracking(nums, depth + 1, temp, result, UsedIndex);

      temp.pop_back();
      UsedIndex.erase(i);

      i++;

      while (i < nums.size() && i > 0 && nums[i] == nums[i - 1]) {
        i++;
      }
    }
  }
};

