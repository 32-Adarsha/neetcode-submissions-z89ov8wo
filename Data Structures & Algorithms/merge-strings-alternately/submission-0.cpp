class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int i = 0 , j = 0 ;
       string combined = "";
       while(i < word1.length() || j < word2.length()) { 
          if(i < word1.length()){
             combined += word1[i]; 
             i++;
          } 
          if(j < word2.length()){
             combined += word2[j]; 
             j++;
          }

       }
       return combined;
    }
};