class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0;
    int result = 0;
    for (auto num : nums) {
      if (num == 1) {
        count++;
        result = max(result, count);
      } else {
        count = 0;
      }
    }

    return result;
  }
};
