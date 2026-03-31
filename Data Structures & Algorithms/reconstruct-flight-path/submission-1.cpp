class Solution {
public:
    map<string, vector<string>> aList;
    vector<string> result;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        for (auto& edge : tickets)
            aList[edge[0]].push_back(edge[1]);

        DFS("JFK");
        reverse(result.begin(), result.end());
        return result;
    }

    void DFS(const string& airport) {
        auto& neighbors = aList[airport];
        while (!neighbors.empty()) {
            string next = neighbors.front();
            neighbors.erase(neighbors.begin());
            DFS(next);
        }
        result.push_back(airport);
    }
};