class Solution {
public:
    bool checkIsomorphic(string s, string t){
        map<char , char> hash; 
       for(int i = 0 ; i < s.length() ; ++i){
          auto it = hash.find(tolower(s[i])); 
          if(it == hash.end()) hash[tolower(s[i])] = tolower(t[i]);
          if(hash[tolower(s[i])]!= tolower(t[i])) return false;
       }
       return true; 
    }

    bool isIsomorphic(string s, string t) {
       return checkIsomorphic(s,t) && checkIsomorphic(t ,s); 
    }
};