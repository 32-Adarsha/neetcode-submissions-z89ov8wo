#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Compare {
  bool operator()(const pair<char, int> &p1, pair<char, int> &p2) {
    return p1.second < p2.second;
  }
};

class Solution {
public:
 string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int,char>> pq;
    if (a) pq.push({a, 'a'});
    if (b) pq.push({b, 'b'});
    if (c) pq.push({c, 'c'});

    string result = "";

    while (!pq.empty()) {
        auto [cnt1, ch1] = pq.top(); pq.pop();

        // If last 2 chars are the same as best candidate, use second-best
        int n = result.size();
        if (n >= 2 && result[n-1] == ch1 && result[n-2] == ch1) {
            if (pq.empty()) break;  // no alternative, we're done

            auto [cnt2, ch2] = pq.top(); pq.pop();
            result += ch2;
            if (cnt2 - 1 > 0) pq.push({cnt2 - 1, ch2});
            pq.push({cnt1, ch1});  // put best back
        } else {
            // Safe to add best (once or twice)
            result += ch1;
            if (cnt1 - 1 > 0) pq.push({cnt1 - 1, ch1});
        }
    }
    return result;
}
};