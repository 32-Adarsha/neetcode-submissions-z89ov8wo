
struct Task {
  int time;
  int count;
  char c;

  Task(int time, int count, char c) : time(time), count(count), c(c) {}
};

struct Compare {
  bool operator()(const Task &t1, const Task &t2) {
    if (t1.time != t2.time) {
      return t1.time > t2.time;
    } else {
      return t1.count < t2.count;
    }
  }
};

class Solution {
public:
  int leastInterval(std::vector<char> &tasks, int n) {
    std::priority_queue<Task, std::vector<Task>, Compare> pq;
    std::unordered_map<char, int> hash;
    for (auto c : tasks) {
      if (hash.find(c) == hash.end()) {
        hash[c] = 0;
      }
      hash[c]++;
    }

    //  INIT:  Set the priority queue with the task
    for (std::pair<char, int> task : hash) {
      Task t = Task(0, task.second, task.first);
      pq.push(t);
    }

    // INIT: set time = 0
    int time = 0;

    while (!pq.empty()) {
      Task t = pq.top();
      pq.pop();

     cout<< t.c << " " << t.time << " " << t.count << endl;
      if (t.time > time) {
        cout<<time << " " << t.time << endl;
        time += (t.time - time);
      }

      time++;


      if (t.count > 1) {
        t.count--;
        t.time += n+1;
        pq.push(t);
      }
    }

    return time;
  }
};