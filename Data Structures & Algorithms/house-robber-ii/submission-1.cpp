class Solution {
public:
  int rob(vector<int> &nums) {
    if(nums.size() < 2){
        return nums[0];
    }
    vector<int> left_nums(nums.begin(), nums.end() - 1);
    vector<int> right_nums(nums.begin() + 1, nums.end());
    int left = rob_1(left_nums);
    int right = rob_1(right_nums);
    return max(left, right);
  }

  int rob_1(vector<int> nums) {
    int len = nums.size();
    nums.push_back(0);
    nums.push_back(0);
    int higest = 0;
    for (int i = len; i >= 0; --i) {
      nums[i] = nums[i] + higest;
      higest = max(nums[i + 1], higest);
    }

    return max(nums[0], nums[1]);
  }
};