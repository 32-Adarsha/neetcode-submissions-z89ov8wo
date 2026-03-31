
struct Link {
  int ui;
  int weight;
  Link(int ui, int weight) : ui(ui), weight(weight) {}
};

struct Compare {
  bool operator()(const Link l1, const Link l2) {
    return l1.weight > l2.weight;
  }
};

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    priority_queue<Link, vector<Link>, Compare> pq;
    map<int, vector<vector<int>>> adjust_list;
    map<int, int> distance;
    for (auto edge : times) {
      if (adjust_list.find(edge[0]) == adjust_list.end()) {
        adjust_list[edge[0]] = {};
      }
      adjust_list[edge[0]].push_back({edge[1], edge[2]});
    }

    for (int i = 1; i <= n; ++i) {
      distance[i] = INT_MAX;
    }
    distance[k] = 0;

    pq.push(Link(k, 0));
    set<int> visiting;

    while (!pq.empty()) {
      auto top = pq.top();
      pq.pop();

      if (visiting.find(top.ui) != visiting.end()) {
        continue;
      }

      visiting.insert(top.ui);

      for (auto node : adjust_list[top.ui]) {
        pq.push(Link(node[0], node[1] + top.weight));
        distance[node[0]] = min(distance[node[0]], node[1] + top.weight);
      }
    }

    int time = 0;
    for (auto [x, y] : distance) {
      time = max(time, y);
    }

    return time == INT_MAX ? -1 : time;
  }
};