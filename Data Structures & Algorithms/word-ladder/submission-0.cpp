class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_map<string, set<string>> adjustList;
    vector<string> AllWordList = {beginWord};
    AllWordList.insert(AllWordList.end(), wordList.begin(), wordList.end());
    
    // NOTE: Making and adjustency list
    for (auto word1 : AllWordList) {
      for (auto word2 : AllWordList) {
        if (word1 != word2) {
          if (adjustList.find(word1) == adjustList.end()) {
            adjustList[word1] = {};
          }
          if (adjustList.find(word2) == adjustList.end()) {
            adjustList[word2] = {};
          }

          bool link1 = adjustList[word1].find(word2) != adjustList[word1].end();
          bool link2 = adjustList[word2].find(word1) != adjustList[word2].end();

          if (hasOnlyOneDiff(word1, word2)) {
            adjustList[word1].insert(word2);
          }
        }
      }
    }

    queue<string> q;
    q.push(beginWord);
    set<string> visiting;
    int depth = 1;
    while (!q.empty()) {
      int qLength = q.size();
      depth++;
      for (int i = 0; i < qLength; ++i) {
        auto currentWord = q.front();
        q.pop();
        visiting.insert(currentWord);
        for (auto nextWord : adjustList[currentWord]) {
          if (visiting.find(nextWord) == visiting.end()) {
            q.push(nextWord);
            if (nextWord == endWord) {
              return depth;
            }
          }
        }
      }

    }
    return 0;
  }

  bool hasOnlyOneDiff(string word1, string word2) {
    int count = 0;
    for (int i = 0; i < word1.length(); ++i) {
      count = (word1[i] != word2[i]) ? count + 1 : count;
      if (count > 1) {
        return false;
      }
    }
    return true;
  }
};