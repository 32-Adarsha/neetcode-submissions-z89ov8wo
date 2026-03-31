struct Dict {
  bool End = false;
  string word = "";  // Store the actual word here
  vector<Dict *> children;
  Dict() : children(26, nullptr) {};  // 26 for a-z
};

class Solution {
private:
  Dict *start;
  vector<string> foundWord = {};

public:
  Solution() { start = new Dict(); }
  
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    // Build trie
    for (string word : words) {
      addWord(word);
    }
    
    // Search from each cell
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        DFS(board, i, j, start);
      }
    }
    
    return foundWord;
  }

  void DFS(vector<vector<char>> &board, int i, int j, Dict *tracker) {
    // Boundary check
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
      return;
    
    char c = board[i][j];
    
    // Already visited or no match in trie
    if (c == '#' || tracker->children[c - 'a'] == nullptr)
      return;
    
    tracker = tracker->children[c - 'a'];
    
    // Found a word
    if (tracker->End) {
      foundWord.push_back(tracker->word);
      tracker->End = false;  // Prevent duplicates
    }
    
    // Mark as visited
    board[i][j] = '#';
    
    // Explore all 4 directions
    DFS(board, i - 1, j, tracker);  // up
    DFS(board, i + 1, j, tracker);  // down
    DFS(board, i, j - 1, tracker);  // left
    DFS(board, i, j + 1, tracker);  // right
    
    // Restore cell
    board[i][j] = c;
  }

  void addWord(string word) {
    Dict *temp = start;
    for (char c : word) {
      int place = c - 'a';
      if (temp->children[place] == nullptr) {
        temp->children[place] = new Dict();
      }
      temp = temp->children[place];
    }
    
    temp->End = true;
    temp->word = word;  // Store the complete word
  }
};