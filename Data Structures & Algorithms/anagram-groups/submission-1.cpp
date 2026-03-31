class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string& word : strs) {
            vector<int> count(26, 0);
            for (char c : word) {
                count[c - 'a']++;
            }
           

            // Create unique key
            string id;
            for (int item : count) {
                id += "," + to_string(item);
            }
            

            // Group words
            anagrams[id].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : anagrams) {
            result.push_back(std::move(entry.second));
        }

        return result;
    }
};
