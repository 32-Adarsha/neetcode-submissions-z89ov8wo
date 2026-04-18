#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int> &v1, const pair<int, int> &v2) {
        return v1.first > v2.first; // min-heap by interval size
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &v1, const vector<int> &v2) {
                 return v1[0] < v2[0];
             });

        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> Result(queries.size(), -1);

        int j = 0;
        for (int i = 0; i < sortedQueries.size(); ++i) {
            int queryVal = sortedQueries[i].first;
            int originalIdx = sortedQueries[i].second;

            // Push all intervals that START at or before the query
            while (j < intervals.size() && intervals[j][0] <= queryVal) {
                int gap = intervals[j][1] - intervals[j][0] + 1;
                pq.push({gap, intervals[j][1]});
                j++;
            }

            // Remove intervals that END before the query
            while (!pq.empty() && pq.top().second < queryVal) {
                pq.pop();
            }

            if (!pq.empty()) {
                Result[originalIdx] = pq.top().first;
            }
        }

        return Result;
    }
};