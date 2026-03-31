#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <system_error>
#include <vector>

using namespace std;

struct Vertex {
  int value;
  int parent;
  vector<Vertex *> connections;
  Vertex(int value, int parent) : value(value), parent(parent) {};
};

class Solution {
public:
  map<int, vector<int>> Nodes;
  vector<int> result;
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    for (int i = 0; i < numCourses; ++i) {
      Nodes[i] = {};
    }

    for (auto course : prerequisites) {
      Nodes[course[0]].push_back(course[1]);
    }

    set<int> visit;
    set<int> running;

    for (auto node : Nodes) {
      if (!dfs(node.first, visit, running)) {
        return {};
      };
    }

    return result;
  }

  bool dfs(int course, set<int> &visit, set<int> &running) {
    if (running.find(course) != running.end()) {
      return false;
    }

    if (visit.find(course) != visit.end()) {
      return true;
    }

    running.insert(course);
    for (auto child : Nodes[course]) {
      if (!dfs(child, visit, running)) {
        return false;
      }
    }
    running.erase(course);
    visit.insert(course);
    result.push_back(course);

    return true;
  }
};
