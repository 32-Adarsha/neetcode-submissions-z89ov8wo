
class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    //  NOTE: make a window;
    if (s2.length() < s1.length())
      return false;

    std::unordered_map<char, int> hash;
    int count = 0;

    for (const char c : s1) {
      if (hash.find(c) == hash.end())
        count++;
      hash[c]++;
    }

    //  NOTE:   pre setting the sliding window with s1 lenght size
    for (int i = 0; i < s1.length(); ++i) {
      if (hash.find(s2[i]) != hash.end()) {
        hash[s2[i]]--;
        if (hash[s2[i]] == 0) {
          count--;
        }
      }
    }

    if (count == 0)
      return true;

    int left = 0;
    int right = s1.length();
    while (right < s2.length()) {
      // NOTE: Add left element if it is presenti the hash;
      //
      if (hash.find(s2[left]) != hash.end()) {
        if (hash[s2[left]] == 0) {
          count++;
        }
        hash[s2[left]]++;
      }

      if (hash.find(s2[right]) != hash.end()) {
        hash[s2[right]]--;
        if (hash[s2[right]] == 0) {
          count--;
        }
      }

      if (count == 0)
        return true;

      right++;
      left++;
    }

    return false;
  }
};

