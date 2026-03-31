
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int lastIndex = cost.size() - 1;
    cost.push_back(0);
    for (int i = lastIndex-1;  i >= 0; --i) {
       cost[i] += min(cost[i + 1], cost[i + 2]);
    }
    return min(cost[0], cost[1]);
  }
};

