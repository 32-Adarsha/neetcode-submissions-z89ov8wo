

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int lastFoundReach = nums.size() - 1;
    for (int i = nums.size() - 2; i > 0; --i) {
      if ((i + nums[i]) >= lastFoundReach) {
        lastFoundReach = i;
        cout<<lastFoundReach<<endl;
      }
    }
    
    return (nums[0] >= lastFoundReach) ? true : false;
  }
};
