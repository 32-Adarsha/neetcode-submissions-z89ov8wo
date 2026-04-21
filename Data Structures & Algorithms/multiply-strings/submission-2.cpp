
class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    string s1 = (num1.length() > num2.length()) ? num1 : num2;
    string s2 = (num1.length() <= num2.length()) ? num1 : num2;
    string result = "";
    int carry = 0;
    for (int i = s2.length() - 1; i >= 0; --i) {
      int index = s2.length() - i - 1;
      for (int j = s1.length() - 1; j >= 0; --j) {
        if (index < result.length()) {
          carry += (result[index] - '0');
        }
        auto r = mult(s1[j], s2[i], carry);
        if (index < result.length()) {
          result[index] = r.second;
        } else {
          result += r.second;
        }
        carry = r.first;

        index++;
      }

      if (carry > 0) {
        if (index < result.length()) {
          result[index] = '0' + carry;
        } else {
          result += '0' + carry;
        }
      }

      carry = 0;
    }

    std::reverse(result.begin(), result.end());
    return result;
  }

  pair<int, char> mult(char c1, char c2, int carry) {
    // At most it will be 81
    int result = (c1 - '0') * (c2 - '0') + carry;
    int over = result / 10;
    char remainder = '0' + result % 10;
    return {over, remainder};
  }
};

