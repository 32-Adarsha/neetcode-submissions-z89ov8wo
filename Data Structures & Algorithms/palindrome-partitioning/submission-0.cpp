
class Solution {
public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> result = {};
    dfs(result, {}, s, 0);
    return result;
  }

  void dfs(std::vector<std::vector<std::string>> &result,
           std::vector<std::string> temp, std::string s, int index) {

    if (index >= s.length()) {

      result.push_back(temp);
      return;
    }

    for (int i = index; i < s.length(); ++i) {
      if (isPalindrom(s, index, i)) {
        // std::cout << s.substr(index, i - index + 1) << std::endl;
        temp.push_back(s.substr(index, i - index + 1));
        dfs(result, temp, s, i + 1);
        temp.pop_back();
      }
    }
  }

  bool isPalindrom(std::string s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }

    return true;
  }
};

