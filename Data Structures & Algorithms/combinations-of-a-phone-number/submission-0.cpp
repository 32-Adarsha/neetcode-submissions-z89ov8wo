
class Solution {
public:
  vector<string> letterCombinations(string digits) {

    // NOTE: Preset the character so it is easy to backtrack
    if(digits.length() < 1){
        return {};
    }
    unordered_map<char, string> mapper = {};
    mapper['2'] = "abc";
    mapper['3'] = "def";
    mapper['4'] = "ghi";
    mapper['5'] = "jkl";
    mapper['6'] = "mno";
    mapper['7'] = "pqrs";
    mapper['8'] = "tuv";
    mapper['9'] = "wxyz";

    vector<string> result;
    backtrack(result, mapper, "", 0, digits);
    return result;
  }

  void backtrack(vector<string> &result, unordered_map<char, string> &link,
                 string temp, int index, string digits) {
    if (index >= digits.length()) {
      result.push_back(temp);
      return;
    }

    for (char c : link[digits[index]]) {
      backtrack(result, link, temp + c, index + 1, digits);
    }
  }
};

