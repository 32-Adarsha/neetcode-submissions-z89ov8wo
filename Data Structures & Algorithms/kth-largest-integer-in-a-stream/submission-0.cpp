class KthLargest {
public:
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int s = 0;
  KthLargest(int k, std::vector<int> &nums) {
    s = k;
    for (int i = 0; i < nums.size(); ++i) {
      if (pq.size() < k) {
        pq.push(nums[i]);
      } else {
        if (pq.top() < nums[i]) {
          pq.pop();
          pq.push(nums[i]);
        }
      }
    }
  }

  int add(int val) {
    if (pq.size() < s) {
      pq.push(val);
    } else {
      if (pq.top() < val) {
        pq.pop();
        pq.push(val);
      }
    }

    return pq.top();
  }
};;