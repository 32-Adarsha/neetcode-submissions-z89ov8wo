
class Solution {
public:
  unordered_map<int, bool> index_hash;
  bool wordBreak(string s, vector<string> &words) {
    return isInDict(s, 0, words);
  }
  bool isInDict(string s, int start_index, vector<string> &words) {
    if (start_index == s.length()) {
      index_hash[start_index] = true;
      return true;
    }
    if (index_hash.find(start_index) != index_hash.end()) {
      return index_hash[start_index];
    }
    bool reach = false;
    for (auto word : words) {
      int len = word.length();
      if (start_index + len > s.length()) // Fixed
        continue;
      string sub_str = s.substr(start_index, len);
      if (sub_str == word) {
        reach =
            reach || isInDict(s, start_index + len, words); // Fixed both issues
      }
    }
    index_hash[start_index] = reach;
    return reach;
  }
};

