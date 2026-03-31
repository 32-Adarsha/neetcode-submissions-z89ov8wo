#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  map<int, int> amountHash;
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
      return 0;
    int result = dfs(coins, amount);
    if (result != INT_MAX)
      return result;
    return -1;
  }

  int dfs(vector<int> &coins, int amount) {

    // NOTE: if the amount is zero than we konw for sure we can use coin to cal
    if (amount == 0)
      return 0;

    // NOTE: Hashing so that in subsequent immediately return if already
    // calculate for the amount
    if (amountHash.find(amount) != amountHash.end())
      return amountHash[amount];

    int minCount = INT_MAX;
    for (auto coin : coins) {

      int deduction = amount - coin;

      if (deduction >= 0) {
        int coin_count = dfs(coins, deduction);

        if (coin_count != INT_MAX) {
          minCount = min(minCount, coin_count + 1);
        }
      }
    }

    amountHash[amount] = minCount;
    return minCount;
  }
};

