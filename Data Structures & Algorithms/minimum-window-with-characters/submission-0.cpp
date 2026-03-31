class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char , int> sHash;
        unordered_map<char , int> tHash;

        // count the number of character in t

        for(char c : t){
            tHash[c]++;
        }


        int i =0;
        int have = 0;
        int need = tHash.size();
        pair<int , int> result = {-1 , -1};
        int windowLength = INT_MAX;


        for(int j = 0; j < s.length() ; ++j){
            sHash[s[j]]++;
            if(tHash.find(s[j]) != tHash.end() && tHash[s[j]] == sHash[s[j]]){
                have++;
            }

                while( have == need){
                    int newWindowLength = j - i +1;
                    if(newWindowLength < windowLength){
                        windowLength = newWindowLength;
                        result = {i , j};
                    }

                    sHash[s[i]]--;
                    if(tHash.find(s[i]) != tHash.end() && sHash[s[i]] < tHash[s[i]]){
                        have--;
                    }
                    
                    i++;
                }
        }


        return windowLength == INT_MAX ? "" : s.substr(result.first , windowLength);

        
    }
};
