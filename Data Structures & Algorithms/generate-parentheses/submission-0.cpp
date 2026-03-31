
class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result = {};
    backTrack(result, "", 0, n);
    return result;
  }

  void backTrack(std::vector<std::string> &result, std::string temp, int weight,
                 int n) {
    if (temp.length() == n * 2) {
      if (weight == 0) {
        result.push_back(temp);
      }

      return;
    }

    std::string option = "()";
    for (const char c : option) {
      if (c == '(' & weight + 1 >= 0) {
        backTrack(result, temp + '(', weight + 1, n);
      } else if (c == ')' & weight - 1 >= 0) {
        backTrack(result, temp + ')', weight - 1, n);
      }
    }
  }
};

