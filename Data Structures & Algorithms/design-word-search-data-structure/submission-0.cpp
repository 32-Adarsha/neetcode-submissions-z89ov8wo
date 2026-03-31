#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Dict {
  bool hasEnd = false;
  char value = ' ';
  vector<Dict *> children;
  Dict(char value) : value(value), children(26, nullptr) {}  // Fixed!
};

class WordDictionary {
private:
  Dict *Start;

public:
  WordDictionary() {
    Start = new Dict(' ');  // Initialize Start!
  }

  void addWord(string word) {
    Dict *temp = Start;
    for (char c : word) {
      cout << c << endl;
      int place = c - 'a';
      if (temp->children[place] == nullptr) {
        temp->children[place] = new Dict(c);
      }
      temp = temp->children[place];
    }
    temp->hasEnd = true;
  }

  bool search(string word) { return BruteSearch(word, Start); }

  bool BruteSearch(string word, Dict *point) {
    if (word == "") {
      if (!point)
        return false;
      return point->hasEnd;
    }

    char c = word[0];  // Process only first character
    if (c != '.') {
      int place = c - 'a';
      if (point->children[place] == nullptr)
        return false;
      return BruteSearch(word.substr(1), point->children[place]);
    } else {
      for (auto const temp : point->children) {
        if (temp == nullptr)
          continue;
        bool value = BruteSearch(word.substr(1), temp);
        if (value)
          return true;
      }
      return false;
    }
  }
};