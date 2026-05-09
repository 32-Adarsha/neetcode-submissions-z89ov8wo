#include <cstdarg>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string id;
    Node *parent;
    vector<pair<double, Node *>> connections;
    Node(string value) : id(value), parent(nullptr) { connections = {}; }
};

class Solution {
private:
    map<string, Node *> Hash;

    Node *getOrCreate(const string &id) {
        if (Hash.find(id) == Hash.end())
            Hash[id] = new Node(id);
        return Hash[id];
    }

    Node *NodeHead(Node *n) {
        if (n->parent == nullptr) return n;
        n->parent = NodeHead(n->parent); // path compression
        return n->parent;
    }

    double bfs(Node *n1, Node *target) {
        queue<pair<double, Node *>> q;
        set<Node *> visited;
        q.push({1.0, n1});
        visited.insert(n1);
        while (!q.empty()) {
            auto [cost, node] = q.front();
            q.pop();
            if (node == target)
                return cost;
            for (auto &[weight, neighbor] : node->connections) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({cost * weight, neighbor});
                }
            }
        }
        return -1.0;
    }

public:
    Solution() {}

    ~Solution() {
        for (auto &[key, node] : Hash)
            delete node;
    }

    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        // Build graph
        for (int i = 0; i < (int)values.size(); ++i) {
            Node *e1 = getOrCreate(equations[i][0]);
            Node *e2 = getOrCreate(equations[i][1]);
            e1->connections.push_back({values[i], e2});
            e2->connections.push_back({1.0 / values[i], e1});
            // Union the two components
            Node *h1 = NodeHead(e1);
            Node *h2 = NodeHead(e2);
            if (h1 != h2)
                h2->parent = h1;
        }

        // Answer queries
        vector<double> result;
        for (auto &query : queries) {
            const string &v1 = query[0];
            const string &v2 = query[1];
            // Unknown variable
            if (Hash.find(v1) == Hash.end() || Hash.find(v2) == Hash.end()) {
                result.push_back(-1.0);
                continue;
            }
            Node *n1 = Hash[v1];
            Node *n2 = Hash[v2];
            // Different components
            if (NodeHead(n1) != NodeHead(n2)) {
                result.push_back(-1.0);
                continue;
            }
            result.push_back(bfs(n1, n2));
        }
        return result;
    }
};