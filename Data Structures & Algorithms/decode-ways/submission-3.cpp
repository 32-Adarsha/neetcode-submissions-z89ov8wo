
class Solution {
public:
  int numDecodings(string s) {

    if (s.length() == 0 || s[0] == '0')
      return 0;

    vector<int> tracker(s.length() + 1, 0);

    tracker[s.length()] = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
      if (s[i] == '0')
        continue;

      if (i == s.length() - 1) {
        tracker[i] = 1;
        continue;
      }

      int value = stoi(s.substr(i, 2));
      int score = (value > 26) ? 0 : tracker[i + 2];
      // NOTE: No possibility

      tracker[i] = score + tracker[i + 1];
      if (tracker[i] == 0)
        return 0;
    }
    int value = stoi(s.substr(0, 2));
    int score = (value > 26) ? 0 : tracker[0 + 2];

    return score + tracker[1];
  }
};

