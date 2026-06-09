
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() > 1) {
      string result = strs[0];
      for (int i = 1; i < strs.size(); ++i) {
        result = common(result, strs[i]);
      }
      return result;
    } else if (strs.size() < 1) {
      return "";
    } else {
      return strs[0];
    }
  }

  string common(string s1, string s2) {
    string result;
    for (int i = 0; i < min(s1.length(), s2.length()); ++i) {
      if (s1[i] == s2[i]) {
        result += s1[i];
      } else {
        break;
      }
    }

    return result;
  }
};

