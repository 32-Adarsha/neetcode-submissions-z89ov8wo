#include <queue>
#include <vector>

using namespace std;

struct Data {
  int index;
  int enqueue_time;
  int processing_time;
  Data(int i, int sTime, int pTime)
      : index(i), enqueue_time(sTime), processing_time(pTime) {};
};

struct Cmp1 {
  bool operator()(const Data &d1, const Data &d2) {
    return d1.enqueue_time > d2.enqueue_time;
  };
};

struct Cmp2 {
  bool operator()(const Data &d1, const Data &d2) {
    if (d1.processing_time == d2.processing_time) {
      return d1.index > d2.index;
    } else {
      return d1.processing_time > d2.processing_time;
    }
  };
};

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    priority_queue<Data, vector<Data>, Cmp1> pq1;
    priority_queue<Data, vector<Data>, Cmp2> pq2;
    vector<int> result;

    for (int i = 0; i < (int)tasks.size(); ++i)
      pq1.push(Data(i, tasks[i][0], tasks[i][1]));

    long long time = 0;
    while (!pq1.empty() || !pq2.empty()) {
      // If CPU is idle, jump forward and load all available tasks
      if (pq2.empty()) {
        time = max(time, (long long)pq1.top().enqueue_time);
        while (!pq1.empty() && pq1.top().enqueue_time <= time) {
          pq2.push(pq1.top());
          pq1.pop();
        }
      }

      Data topTask = pq2.top();
      pq2.pop();
      result.push_back(topTask.index);
      time += topTask.processing_time; // advance clock by processing time

      // Load all tasks that are now available
      while (!pq1.empty() && pq1.top().enqueue_time <= time) {
        pq2.push(pq1.top());
        pq1.pop();
      }
    }
    return result;
  }
};