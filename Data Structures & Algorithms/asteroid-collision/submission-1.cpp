
class Solution {
public:
  std::vector<int> asteroidCollision(std::vector<int> &asteroids) {

    std::stack<int> BigBang;
    for (auto asteroid : asteroids) {
      if (!BigBang.empty()) {
        int temp = asteroid;
        while (!BigBang.empty() && DifferentSign(BigBang.top(), temp)) {
          int top = BigBang.top();
          BigBang.pop();
          temp = (abs(top) > abs(temp))   ? top
                 : (abs(temp) > abs(top)) ? temp
                                          : 0;
          if (temp == 0) {
            break;
          }
        }
        if (temp != 0) {
          BigBang.push(temp);
        }
      } else {
        BigBang.push(asteroid);
      }
    }

    std::vector<int> result;
    while (!BigBang.empty()) {
      result.push_back(BigBang.top());
      BigBang.pop();
    }

    std::reverse(result.begin(), result.end());
    return result;
  }

  bool DifferentSign(int first, int second) {
    if ((first > 0 && second < 0)) {
      return true;
    }

    return false;
  }
};

