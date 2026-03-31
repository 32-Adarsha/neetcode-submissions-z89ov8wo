
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    set<int> Sums;
    int total = 0;
    for (int i = 0; i < nums.size(); ++i) {
      total += nums[i];

      vector<int> Temp;
      for (auto sum : Sums) {
        Temp.push_back(nums[i] + sum);
      }

      Sums.insert(Temp.begin(), Temp.end());
      Sums.insert(nums[i]);
    }

    if (total % 2 != 0)
      return false;

    if (Sums.find(total / 2) != Sums.end())
      return true;

    return false;
  }
};

