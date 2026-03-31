
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sum = INT_MIN;
    int left = 0;
    int right = 0;
    int tempSum = 0;
    while (right < nums.size()) {
      tempSum += nums[right];
      sum = max(tempSum, sum);
      if (tempSum < 0) {
        tempSum = 0;
      }

      right++;
    }

    return sum;
  }
};

