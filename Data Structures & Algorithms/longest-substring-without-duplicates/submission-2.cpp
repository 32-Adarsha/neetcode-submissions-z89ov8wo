class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> hash_map;
        int i = 0;
        int j = 0;
        int maxLength = 0;
        while (j < s.length()){
           maxLength = max(maxLength , j - i);
            if(hash_map.find(s[j]) != hash_map.end()){
                int temp = i;
                i = hash_map[s[j]]+1;

                while (temp < i){
                    hash_map.erase(s[temp]);
                    temp++;
                }
                
                hash_map[s[j]] = j;
            } else {
                hash_map.insert({s[j] , j});
            }

            j++;
            
            cout<<i<<" "<<j<<" "<<maxLength<<endl; 
           
        }
maxLength = max(maxLength , j - i);
        

        return maxLength;


    }
};
