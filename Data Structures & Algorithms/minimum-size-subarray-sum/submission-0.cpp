
class Solution {
public:
  int minSubArrayLen(int target, std::vector<int> &nums) {
    int left = 0;
    int right = 0;
    int window_size = nums.size() + 1;
    int total = 0;

    while (left < nums.size()) {
      // NOTE: increment right
      while (total < target && right < nums.size()) {
        total += nums[right];
        right++;
      }

      if (total >= target) {
        window_size = std::min(window_size, right - left);
      }

      while (total >= target && left < nums.size()) {
        window_size = std::min(window_size, right - left);
        total -= nums[left];
        left++;
      }

      if (total < target && right >= nums.size()) {
        break;
      }
    }

    window_size = (window_size > nums.size()) ? 0 : window_size;
    return window_size;
  }
};
