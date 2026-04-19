
class Solution {
public:
  bool isHappy(int n) {
    set<int> Hash;

    while (Hash.find(n) == Hash.end()) {
      Hash.insert(n);
      n = DigitSquareSum(n);
      if (n == 1) {
        return true;
      }
    }
    return false;
  }

  int DigitSquareSum(int n) {
    int total = 0;
    while (n != 0) {
      int last = n % 10;
      total += last * last;
      n = n / 10;
    }

    return total;
  }
};

