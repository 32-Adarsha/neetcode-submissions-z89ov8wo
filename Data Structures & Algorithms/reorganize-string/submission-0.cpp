struct Compare {
    bool operator()(const pair<char,int>& a, const pair<char,int>& b) {
        return a.second < b.second; // max-heap by frequency
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> count;
        for (char c : s) count[c]++;

        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        for (auto& [ch, cnt] : count) {
            if (cnt > (s.size() + 1) / 2) return ""; // impossible
            pq.push({ch, cnt});
        }

        string result;
        while (pq.size() >= 2) {
            auto [c1, f1] = pq.top(); pq.pop();
            auto [c2, f2] = pq.top(); pq.pop();

            result += c1;
            result += c2;

            if (f1 - 1 > 0) pq.push({c1, f1 - 1});
            if (f2 - 1 > 0) pq.push({c2, f2 - 1});
        }

        // At most one character left
        if (!pq.empty()) result += pq.top().first;

        return result;
    }
};