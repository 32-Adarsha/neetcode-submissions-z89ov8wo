class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int> , std::greater<int>> pq;

    for (int i = 0; i < nums.size(); ++i) {
      if (pq.size() < k) {
        pq.push(nums[i]);
      } else {
        if (nums[i] > pq.top()) {
          std::cout << pq.top() << std::endl;
          pq.pop();
          pq.push(nums[i]);
        }
      }
    }

    return pq.top();
  }
};