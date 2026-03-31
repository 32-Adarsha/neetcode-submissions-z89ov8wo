#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> opt;

    for (std::string s : tokens) {

      if (s == "+") {
        int last = opt.top();
        opt.pop();
        int second_last = opt.top();
        opt.pop();
        opt.push(last + second_last);
      } else if (s == "-") {
        int last = opt.top();
        opt.pop();
        int second_last = opt.top();
        opt.pop();
        opt.push(second_last - last);
      } else if (s == "*") {
        int last = opt.top();
        opt.pop();
        int second_last = opt.top();
        opt.pop();
        opt.push(last * second_last);
      } else if (s == "/") {
        int last = opt.top();
        opt.pop();
        int second_last = opt.top();
        opt.pop();
        opt.push(second_last / last);
      } else {
        opt.push(std::stoi(s));
      }
    }

    return opt.top();
  }
};