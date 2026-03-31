#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Location {
  int height;
  pair<int, int> position;
  Location(int height, pair<int, int> position)
      : height(height), position(position) {}
};

struct Compare {
  bool operator()(const Location &l1, const Location &l2) {
    return l1.height > l2.height;
  }
};

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int waterLevel = 0;
    int size = grid.size() - 1;

    set<pair<int, int>> CanSwim;
    set<pair<int, int>> visiting;
    priority_queue<Location, vector<Location>, Compare> pq;
    pq.push(Location(grid[0][0], {0, 0}));
    visiting.insert({0, 0});

    while (CanSwim.find({size, size}) == CanSwim.end()) {
      while (!pq.empty() && pq.top().height <= waterLevel) {
        Location top = pq.top();
        pq.pop();
        CanSwim.insert(top.position);
        //cout<<top.position.first<< " " << top.position.second << " " << top.height<< endl;
        for (auto [x, y] : direction) {
          int newX = top.position.first + x;
          int newY = top.position.second + y;

          if (newX >= 0 && newX < grid.size() && newY >= 0 and
              newY < grid[0].size() &&
              visiting.find({newX, newY}) == visiting.end()) {
            pq.push(Location(grid[newX][newY], {newX, newY}));
            visiting.insert({newX, newY});
          }
        }
      }

      if (CanSwim.find({size, size}) != CanSwim.end())
        return waterLevel;
      waterLevel = pq.top().height;
    }

    return waterLevel;
  }
};