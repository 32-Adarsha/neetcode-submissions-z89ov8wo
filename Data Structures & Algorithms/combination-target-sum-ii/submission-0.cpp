
class Solution {

public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> result = {};
    dfs(result, candidates, 0, {}, target);
    return result;
  }

  void dfs(std::vector<std::vector<int>> &result, std::vector<int> &candidates,
           int start, std::vector<int> temp, int target) {
    if (target == 0) {
      result.push_back(temp);
      return;
    }

    if (target < 0) {
      return;
    }

    int i = start;
    while (i < candidates.size()) {
      temp.push_back(candidates[i]);
      target -= candidates[i];
      dfs(result, candidates, i + 1, temp, target);
      target += candidates[i];
      temp.pop_back();

      i++; 
      while(i < candidates.size() && candidates[i-1] == candidates[i]){
        i++;
      }
      
    }
  }
}; 
