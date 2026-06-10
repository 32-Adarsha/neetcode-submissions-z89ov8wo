
class Solution {
public:
  string simplifyPath(string path) {
    stack<string> stack_path;
    int left = 0;
    int right = 1;
    while (right < path.size()) {
      string dir;
      while (right < path.size() && path[right] != '/') {
        dir += path[right];
        right++;
      }

      if (dir != "") {
        if (dir == "..") {
          if (!stack_path.empty()) {
            stack_path.pop();
          }
        } else if (dir != ".") {
          stack_path.push(dir);
        }
      }

      left = right;
      right += 1;
    }

    string result;
    while (!stack_path.empty()) {
      result = "/" + stack_path.top() + result;
      stack_path.pop();
    }

    if (result == "") {
      result = "/";
    }

    return result;
  }
};

