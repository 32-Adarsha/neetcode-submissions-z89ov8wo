
class Solution {
public:
  bool checkValidString(string str) {
    stack<int> left, right;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '(') {
        left.push(i);
      } else if (str[i] == '*') {
        right.push(i);
      } else {
        if (left.empty() && right.empty()) {
          return false;
        } else if (!left.empty()) {
          left.pop();
        } else {
          right.pop();
        }
      }
    }

    if (left.size() > right.size()) {
      return false;
    }

    while (!left.empty()) {
      if (left.top() > right.top()) {
        return false;
      } else {
        left.pop();
        right.pop();
      }
    }

    return true;
  }
};

