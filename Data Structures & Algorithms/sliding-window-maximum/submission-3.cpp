class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    // NOTE: make and window that of size k

    std::deque<int> window;
    for (int i = 0; i < k; ++i) {
      if (window.empty()) {
        window.push_back(nums[i]);
        continue;
      }

      while (!window.empty() && window.back() < nums[i]) {
        window.pop_back();
      }

      window.push_back(nums[i]);
    }

    int left = 0;
    int right = k;
    std::vector<int> maxTracker;

    while (right < nums.size()) {
      maxTracker.push_back(window.front());
      if (nums[left] == window.front() || window.size() == k) {
        window.pop_front();
      }

      while (!window.empty() && window.back() < nums[right]) {
        window.pop_back();
      }

      window.push_back(nums[right]);
      left++;
      right++;
    }

    maxTracker.push_back(window.front());

    return maxTracker;
  }
};

