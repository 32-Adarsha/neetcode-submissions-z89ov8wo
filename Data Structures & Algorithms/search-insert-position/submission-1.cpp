
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      if (target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (right == -1) {
      return 0;
    }

    if (left == nums.size()) {
      return nums.size();
    }

    cout << left << " " << right << endl;
    return right + 1;
  }
};

