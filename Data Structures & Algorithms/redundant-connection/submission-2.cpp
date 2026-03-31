
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    set<int> vertex;
    map<int, int> link;
    vector<int> result = {};
    for (auto edge : edges) {
      if (vertex.find(edge[0]) != vertex.end() &&
          vertex.find(edge[1]) != vertex.end() &&
          findRoot(link, edge[0]) == findRoot(link, edge[1])) {
        result = edge;
      }

      if (link.find(edge[0]) == link.end()) {
        link[edge[0]] = edge[0];
        vertex.insert(edge[0]);
      }

      if (link.find(edge[1]) == link.end()) {
        link[edge[1]] = edge[1];
        vertex.insert(edge[1]);
      }

      link[findRoot(link, edge[1])] = findRoot(link, edge[0]);
    }

    return result;
  }

  int findRoot(map<int, int> &link, int value) {
    while (link[value] != value) {
      value = link[value];
    }
    return value;
  }
};