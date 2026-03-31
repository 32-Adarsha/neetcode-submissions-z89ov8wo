
class Solution {

public:
  map<pair<int, int>, bool> memo;
  bool isInterleave(string s1, string s2, string s3) {
    int i = 0;
    int j = 0;
    int k = 0;

    if ((s1.length() + s2.length()) != s3.length()) {
      return false;
    }

    return dfs(0, 0, 0, s1, s2, s3);
  }

  bool dfs(int i, int j, int k, string s1, string s2, string s3) {
    if (i >= s1.length() && j >= s2.length()) {
      return (k >= s3.length()) ? true : false;
    }

    auto it = memo.find({i, j});
    if (it != memo.end()) {
      return memo[{i, j}];
    }

    if (i < s1.length() && s1[i] == s3[k]) {
      if (dfs(i + 1, j, k + 1, s1, s2, s3)) {
        return true;
      };
    }

    if (j < s2.length() && s2[j] == s3[k]) {
      return dfs(i, j + 1, k + 1, s1, s2, s3);
    }

    memo[{i, j}] = false;

    return false;
  }
};

