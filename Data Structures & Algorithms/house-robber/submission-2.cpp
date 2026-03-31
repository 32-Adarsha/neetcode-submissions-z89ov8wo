#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int nums_length = nums.size();
    


    nums.push_back(0);
    nums.push_back(0);
    int highest = 0;
    for (int i = nums_length; i >= 0; --i) {
      nums[i] = nums[i] + highest;
      highest = max(nums[i + 1], highest);
    }

    if (nums_length >= 2)
      return max(nums[0], nums[1]);
    return nums[0];
  }
};