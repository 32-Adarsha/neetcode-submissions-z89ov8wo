
class Solution {
public:
  double myPow(double x, int y) {
    if (y < 0) {
      x = 1 / x;
      y = -y;
    }

    double result = 1;
    while (y > 0) {
      if (y & 1) {
        result *= x;
      }

      x *= x;
      y >>= 1;
    }

    return result;
  }
};

