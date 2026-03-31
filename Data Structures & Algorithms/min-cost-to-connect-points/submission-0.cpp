#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct Edge {
    vector<int> first;
    vector<int> last;
    int weight;
    Edge(vector<int> first, vector<int> last) : first(first), last(last) {
        weight = abs(first[0] - last[0]) + abs(first[1] - last[1]);
    }
};

struct Compare {
    bool operator()(const Edge &e1, const Edge &e2) {
        return e1.weight > e2.weight;
    }
};

class Solution {
public:
    map<vector<int>, vector<int>> Root;

    // Find root with path compression
    vector<int> find(vector<int> node) {
        if (Root.find(node) == Root.end()) {
            Root[node] = node; // Initialize: node is its own root
        }
        if (Root[node] != node) {
            Root[node] = find(Root[node]); // Path compression
        }
        return Root[node];
    }

    // Union two sets
    bool unite(vector<int> a, vector<int> b) {
        vector<int> rootA = find(a);
        vector<int> rootB = find(b);
        if (rootA == rootB) return false; // Already connected → would form a cycle
        Root[rootA] = rootB;
        return true;
    }

    int minCostConnectPoints(vector<vector<int>> &points) {
        priority_queue<Edge, vector<Edge>, Compare> pq;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                pq.push(Edge(points[i], points[j]));
            }
        }

        int cost = 0;
        int edgesUsed = 0;
        int target = points.size() - 1; // MST needs n-1 edges

        while (!pq.empty() && edgesUsed < target) {
            Edge e = pq.top();
            pq.pop();

            if (unite(e.first, e.last)) { // Only add edge if it doesn't form a cycle
                cost += e.weight;
                edgesUsed++;
            }
        }
        return cost;
    }
};