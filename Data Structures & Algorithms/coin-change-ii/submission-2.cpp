
class Solution {
private:
public:
  int change(int amount, vector<int> &coins) {
    vector<int> Ways(amount + 1, 0);
    Ways[0] = 1;

    for (int i = coins.size() - 1; i >= 0; --i) {
      dfs(coins[i], amount, Ways);
      cout << coins[i] << "=> ";
      // for (int j = 0; j < Ways.size(); ++j) {
      //   cout << Ways[j] << " ";
      // }
      // cout << endl;
    }

    return Ways[amount];
  }

  void dfs(int coin, int amount, vector<int> &ways) {
    if (amount == 0) {
      ways[0] = 1;
      return;
    }
    dfs(coin, amount - 1, ways);
    int index = amount - coin;
    if (index >= 0) {
      ways[amount] = ways[amount] + ways[index];
    }
  }
};

