class Solution {
public:
  int lastStoneWeight(std::vector<int> &stones) {
    std::priority_queue<int, std::vector<int>> pq;

    for (int i = 0; i < stones.size(); ++i) {
      pq.push(stones[i]);
    }

    while (pq.size() > 1) {
      int s1 = pq.top();
      pq.pop();
      int s2 = pq.top();
      pq.pop();


      if (s1 == s2)
        continue;

      pq.push(abs(s1 - s2));
    }

    return (pq.size() > 0) ? pq.top() : 0;
  }
};