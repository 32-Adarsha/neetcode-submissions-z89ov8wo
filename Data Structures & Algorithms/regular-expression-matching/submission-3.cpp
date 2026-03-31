class Solution {
    map<pair<int,int>, bool> dp;

public:
    bool isMatch(string s, string p) {
        dp.clear();
        return dfs(0, 0, s, p);
    }

    bool dfs(int i, int j, string& s, string& p) {
        // Both exhausted → match
        if (j == p.size()) return i == s.size();

        auto key = make_pair(i, j);
        auto it = dp.find(key);
        if (it != dp.end()) return it->second;

        bool firstMatch = i < s.size() && (p[j] == s[i] || p[j] == '.');

        bool result;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Option 1: skip "x*" (zero occurrences)
            // Option 2: use one occurrence and stay at j
            result = dfs(i, j + 2, s, p) ||
                     (firstMatch && dfs(i + 1, j, s, p));
        } else {
            result = firstMatch && dfs(i + 1, j + 1, s, p);
        }

        return dp[key] = result;
    }
};