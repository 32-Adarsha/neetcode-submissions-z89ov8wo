
class Solution {
public:
  int jump(vector<int> &nums) {
    int res = 0;
    int l = 0;
    int r = 0;

    while (r < nums.size() - 1) {
      int furthest = 0;

      for (int i = l; i < r + 1; ++i) {
        furthest = max(furthest, i + nums[i]);
      }

      l = r + 1;
      r = furthest;
      res++;
    }

    return res;
  }
};