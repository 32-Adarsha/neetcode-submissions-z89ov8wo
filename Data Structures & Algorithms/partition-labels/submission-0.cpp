
class Solution {
public:
  vector<int> partitionLabels(string s) {
    map<char, int> count;

    for (auto c : s) {
      auto it = count.find(c);
      if (it == count.end()) {
        count[c] = 1;
      } else {
        count[c]++;
      }
    }

    int i = 0;
    set<char> characters = {};
    characters.insert(s[0]);
    int subStringCount = 0;
    vector<int> result = {};
    while (i < s.size()) {
      characters.insert(s[i]);
      count[s[i]]--;
      if (count[s[i]] == 0) {
        characters.erase(s[i]);
      }
      if (characters.size() == 0) {
        result.push_back(subStringCount + 1);
        subStringCount = 0;
      } else {
        subStringCount++;
      }

      i++;
    }
    return result;
  }
};

