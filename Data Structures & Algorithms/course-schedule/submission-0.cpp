struct DGraph {
  int value;
  vector<DGraph *> child;
  int state = 0;
};

class Solution {
private:
  map<int, DGraph *> hash;

public:
  bool canFinish(int numCourse, vector<vector<int>> &prequisites) {
    for (const vector<int> &item : prequisites) {
      if (hash.find(item[0]) == hash.end()) {
        hash[item[0]] = new DGraph{item[0], {}, 0};
      }

      if (hash.find(item[1]) == hash.end()) {
        hash[item[1]] = new DGraph{item[1], {}, 0};
      }

      hash[item[0]]->child.push_back(hash[item[1]]);
    }

    for (const auto &item : hash) {
      if (item.second->state == 0) {
        if (hasCycle(item.second)) {
          return false;
        }
      }
    }

    return true;
  }

  bool hasCycle(DGraph *node) {
    if (node->state == 1)
      return true;
    if (node->state == 2)
      return false;

    node->state = 1;

    for (DGraph *children : node->child) {
      bool result = hasCycle(children);
      if (result)
        return true;
    }

    node->state = 2;
    return false;
  }
};