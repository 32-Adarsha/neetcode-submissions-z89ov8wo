class Solution {
public:
  map<pair<int, bool>, int> Memo;
  int maxProfit(vector<int> &prices) {
    bool buying = true;
    return DFS(0, prices.size(), true, prices);
  }

  int DFS(int i, int size, int buying, vector<int> &prices) {
    if (i >= size) {
      return 0;
    }

    if (Memo.find({i, buying}) != Memo.end()) {
      return Memo[{i, buying}];
    }

    int cooldown = DFS(i + 1, size, buying, prices);
    if (buying) {
      int buy = DFS(i + 1, size, !buying, prices) - prices[i];
      Memo[{i, buying}] = max(buy, cooldown);
    } else {
      int sell = DFS(i + 2, size, !buying, prices) + prices[i];
      Memo[{i, buying}] = max(sell, cooldown);
    }

    return Memo[{i, buying}];
  }
};

;
