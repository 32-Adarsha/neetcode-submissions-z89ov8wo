
class Solution {
private:
  set<string> Jam;

public:
  int openLock(vector<string> &deadends, string target) {

    vector<int> State = {0, 0, 0, 0};
    for (string value : deadends) {
      Jam.insert(value);
    }

    queue<string> q;
    q.push("0000");
    Jam.insert("0000");
    for (auto d : deadends) {
      if (d == "0000") {
        return -1;
      }
      Jam.insert(d);
    }

    int step = 0;
    while (!q.empty()) {
      int qSize = q.size();
      for (int i = 0; i < qSize; ++i) {
        string top = q.front();
        q.pop();
        if (top == target) {
          return step;
        }

        for (auto chid : Children(top)) {
          q.push(chid);
        }
      }
      step++;
    }

    return -1;
  }

  vector<string> Children(string value) {
    vector<string> res;
    for (int i = 0; i < value.size(); ++i) {
      string temp = value;
      string temp2 = value;
      // NOTE: adding one at each positon
      temp[i] = ((temp[i] - '0' + 1) % 10) + '0';
      temp2[i] = ((temp2[i] - '0' - 1 + 10) % 10) + '0';

      if (Jam.find(temp) == Jam.end()) {
        res.push_back(temp);
        Jam.insert(temp);
      }

      if (Jam.find(temp2) == Jam.end()) {
        res.push_back(temp2);
        Jam.insert(temp2);
      }
    }

    return res;
  }
};