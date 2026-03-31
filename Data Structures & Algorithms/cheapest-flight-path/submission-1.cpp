
struct FlightCost {
  int flight;
  int cost;
  int hop;
  FlightCost(int flight, int cost, int hop)
      : flight(flight), cost(cost), hop(hop) {}
};

struct Compare {
  bool operator()(const FlightCost &f1, const FlightCost &f2) {
    return f1.cost > f2.cost;
  }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<pair<int,int>>> flightPath;
        for (auto& flight : flights)
            flightPath[flight[0]].push_back({flight[1], flight[2]});

        // {cost, node, stops_remaining}
        priority_queue<FlightCost, vector<FlightCost>, Compare> pq;
        pq.push(FlightCost(src, 0, k + 1));

        // Track minimum cost to reach each node at each hop count
        map<pair<int,int>, int> visited; // {node, hops_remaining} -> cost

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();

            if (top.flight == dst) return top.cost; // Dijkstra guarantees cheapest first

            if (top.hop <= 0) continue;

            auto key = make_pair(top.flight, top.hop);
            if (visited.count(key) && visited[key] <= top.cost) continue;
            visited[key] = top.cost;

            for (auto& [next, price] : flightPath[top.flight])
                pq.push(FlightCost(next, top.cost + price, top.hop - 1));
        }

        return -1; // not INT_MAX — LeetCode expects -1 if unreachable
    }
};