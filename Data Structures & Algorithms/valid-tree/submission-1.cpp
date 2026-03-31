#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Tree {
  int visitCount = 0;
  int value;
  vector<Tree *> child;
  Tree(int value) {
    value = value;
    child = {};
  }
};

class Solution {
public:
  // To get already existing node of paticular value
  map<int, Tree *> hash;

  bool validTree(int n, vector<vector<int>> &edges) {
    for (const vector<int> &value : edges) {
      if (hash.find(value[0]) == hash.end()) {
        Tree *node = new Tree(value[0]);
        hash[value[0]] = node;
      }

      if (hash.find(value[1]) == hash.end()) {
        Tree *node = new Tree(value[1]);
        hash[value[1]] = node;
      }

      hash[value[0]]->child.push_back(hash[value[1]]);
      hash[value[1]]->child.push_back(hash[value[0]]);
    }

    int repeat = 0;

    for (const auto &pair : hash) {
      if (pair.second->visitCount != 2) {
        repeat += 1;
        if (repeat > 1)
          return false;
        bool hasCycle = isCycle(pair.second, nullptr);
        if (hasCycle) {
          return false;
        }
      }
    }

    return true;
  }

private:
  bool isCycle(Tree *node, Tree *parent) {
    if (node->visitCount == 1) {
      return true;
    }

    node->visitCount = 1;

    for (auto c : node->child) {
      if (parent == nullptr || parent != c) {
        bool hasCycle = isCycle(c, node);
        if (hasCycle)
          return true;
      }
    }

    node->visitCount += 1;
    return false;
  }
};

