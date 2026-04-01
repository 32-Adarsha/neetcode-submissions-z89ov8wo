using namespace std;
class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    int hop = 0;
    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;
    while (!q.empty()) {
      int s = q.size();
      for (int i = 0; i < s; ++i) {
        int f = q.front();
        q.pop();
        if (f == n - 1) {
          return hop;
        }
        int limit = min(n - 1, f + nums[f]);
        for (int j = limit; j > f; --j) {
          if (visited[j]) break;
          visited[j] = true;
          q.push(j);
        }
      }
      hop++;
    }
    return hop;
  }
};