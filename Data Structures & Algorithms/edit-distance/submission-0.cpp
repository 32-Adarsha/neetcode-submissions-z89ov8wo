
class Solution {
  int maxReplacement = 0;

public:
  map<pair<int, int>, int> dp;
  int numDfs = 0;
  int minDistance(string word1, string word2) {
    maxReplacement = max(word1.length(), word2.length());
    return dfs(0, 0, word1, word2);
  }

  int dfs(int i, int j, string &word1, string &word2) {
    if (i >= word1.length() && j >= word2.length()) {
      return 0;
    }

    auto it = dp.find({i, j});
    if (it != dp.end()) {
      return dp[{i, j}];
    }

    // i and j  are equall

    int dist2 = maxReplacement;
    if (i < word1.length() && j < word2.length()) {
      // cout << "Equal = " << word1[i] << " " << word2[j] << endl;
      int cost = (word1[i] == word2[j]) ? 0 : 1;
      dist2 = min(dist2, dfs(i + 1, j + 1, word1, word2) + cost);
    }

    // Insert ( assuming )
    if (i <= word1.length() && j < word2.length()) {
      // cout << "Insert = " << word1[i] << " " << word2[j] << endl;
      numDfs++;
      dist2 = min(dist2, dfs(i, j + 1, word1, word2) + 1);
    }

    // Remove ( Simulating removal of ith value by incrementing)
    if (i < word1.length()) {
      // cout << "Remove = " << word1[i] << " " << word2[j] << endl;
      numDfs++;
      dist2 = min(dist2, dfs(i + 1, j, word1, word2) + 1);
    }

    dp[{i, j}] = dist2;
    return dist2;
  }
};

