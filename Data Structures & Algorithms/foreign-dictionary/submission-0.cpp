
class Solution {
private:
  bool dfs(char c, vector<char> &result, unordered_map<char, bool> &visited,
           unordered_map<char, unordered_set<char>> &adj) {
    if (visited.find(c) != visited.end()) {
      return visited[c];
    }

    visited[c] = true;
    for (auto neigh : adj[c]) {
      if (dfs(neigh, result, visited, adj)) {
        return true;
      };
    }

    visited[c] = false;
    result.push_back(c);
    return false;
  }

public:
  string foreignDictionary(vector<string> &words) {
    unordered_map<char, unordered_set<char>> adj;
    for (auto word : words) {
      for (auto c : word) {
        if (adj.find(c) == adj.end()) {
          adj[c];
        }
      }
    }

    for (int i = 0; i < words.size() - 1; i++) {
      string w1 = words[i], w2 = words[i + 1];
      int len = min(w1.length(), w2.length());

      if (w1.length() > w2.length() && w1.substr(0, len) == w2.substr(0, len)) {
        return "";
      }

      for (int j = 0; j < len; j++) {
        if (w1[j] != w2[j]) {
          adj[w1[j]].insert(w2[j]);
          break;
        }
      }
    }

    unordered_map<char, bool> visited = {};
    vector<char> result = {};
    for (auto p : adj) {
      if (dfs(p.first, result, visited, adj)) {
        return "";
      }
    }

    string newResult = "";
    for (char c : result) {
      newResult = c + newResult;
    }

    return newResult;
  }
};
