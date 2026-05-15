
class Solution {
public:
  std::vector<int> findMinHeightTrees(int n,
                                      std::vector<std::vector<int>> &edges) {
    if(n == 1){
        return {0};
    }
    map<int, vector<int>> adj_list;
    for (auto edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }

    map<int, int> edge_cnt;
    deque<int> leaves;

    for (auto item : adj_list) {
      edge_cnt[item.first] = item.second.size();
      if (edge_cnt[item.first] == 1) {
        leaves.push_back(item.first);
      }
    }

    while (!leaves.empty()) {
      if (n <= 2) {
        vector<int> result(leaves.begin(), leaves.end());
        return result;
      }
      int length = leaves.size();
      for (int i = 0; i < length; ++i) {
        for (auto child : adj_list[leaves.front()]) {
          edge_cnt[child]--;
          if (edge_cnt[child] == 1) {
            leaves.push_back(child);
          }
        }
        leaves.pop_front();
        n -= 1;
      }
    }

    return {};
  }
};