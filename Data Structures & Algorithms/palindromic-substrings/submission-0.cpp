
class Solution {
private:
  int count = 0;

public:
  int countSubstrings(string s) {
    for (int i = 0; i < s.length(); ++i) {
      // odd
      int left = i;
      int right = i;
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        count++;
        left--;
        right++;
      }

      // even
      left = i;
      right = i + 1;
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        count++;
        left--;
        right++;
      }
    }

    return count;
  }
};

;


