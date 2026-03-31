class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        for (int i = 0; i < parent.size(); i++) { 
            parent[i] = i;
        }


        for (const auto &edge : edges) {

            int p1 = parent[edge[0]];

            while (p1 != parent[p1]) {
                p1 = parent[p1];
            }

            int p2 = parent[edge[1]];

            while (p2 != parent[p2]) {
                p2 = parent[p2];
            }

            if (p1 == p2) continue;

            parent[p2] = p1;

            n -= 1;
        }

    
 
    
        return n;
    };    
};

