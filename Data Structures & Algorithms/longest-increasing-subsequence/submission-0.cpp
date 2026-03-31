
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> lng(nums.size(), 1);
    int longest = 1;
    for (int i = 0; i < nums.size(); ++i) {
      int j = i - 1;
      int curr_longest = 1;
      while (j >= 0) {
        if (nums[i] > nums[j]) {
          curr_longest = max(curr_longest, 1 + lng[j]);
        }
        j--;
      }
      lng[i] = curr_longest;
      if (curr_longest > longest) {
        longest = curr_longest;
      }
    }

    return longest;
  }
};

