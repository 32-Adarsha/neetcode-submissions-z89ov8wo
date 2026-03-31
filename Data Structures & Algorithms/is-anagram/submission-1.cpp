class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()) {
            return false;
        }

        unordered_map<char , int> hash;

        for(char c : s){
            if(hash.find(c) != hash.end()){
                hash[c] += 1;
            } else {
                hash.insert({c , 1});
            }
        }


        // check the other string against the previous hash

        for(char c : t){
            if(hash.find(c) == hash.end()){
                return false;
            }
            
            hash[c] -= 1;
            if (hash[c] == 0){
                hash.erase(c);
            }

        }

        return true;

    }
};
