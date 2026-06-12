#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct IPO {
  int profit;
  int captial;
  IPO(int profit, int captial) : profit(profit), captial(captial) {}
};

struct Compare {
  bool operator()(const IPO &p1, const IPO &p2) {
    return p1.profit < p2.profit;
  }
};

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    vector<IPO> ipos;
    for (int i = 0; i < profits.size(); ++i) {
      ipos.push_back(IPO(profits[i], capital[i]));
    }

    sort(ipos.begin(), ipos.end(),
         [](const IPO &p1, const IPO &p2) { return p1.captial < p2.captial; });

    priority_queue<IPO, vector<IPO>, Compare> pq;
    int revenue = w;
    int index = 0;

    while (k > 0) {
      while (index < (int)profits.size() && ipos[index].captial <= revenue) {
        pq.push(ipos[index]);
        index++;
      }
      if (!pq.empty()) {
        revenue += pq.top().profit;
        pq.pop();
        k--;
      } else {
        break;
      }
    }
    return revenue;
  }
};