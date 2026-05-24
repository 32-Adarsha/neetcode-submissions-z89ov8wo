
class Solution {
private:
  set<char> num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

public:
  string decodeString(string s) {
    stack<char> stk;
    for (char c : s) {
      stk.push(c);
    }

    string result = "";
    while (!stk.empty()) {
      if (stk.top() == ']') {
        stk.pop();
        result = recur(stk) + result;
      } else {
        result = stk.top() + result;
        stk.pop();
      }
    }

    return result;
  }

  string recur(stack<char> &stk) {
    string result = "";

    while (!stk.empty() && stk.top() != '[') {
      if (stk.top() == ']') {
        stk.pop();
        result = recur(stk) + result;
      } else {
        result = stk.top() + result;
        cout << result << endl;
        stk.pop();
      }
    }
    if (!stk.empty() && stk.top() == '[') {
      stk.pop();
    }
    string number = "";
    while (!stk.empty() && num.find(stk.top()) != num.end()) {
      number = stk.top() + number;
      stk.pop();
    }
    string temp = result;
    for (int i = 0; i < stoi(number) - 1; ++i) {
      result += temp;
    }

    return result;
  }
};

