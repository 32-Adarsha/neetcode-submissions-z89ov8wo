class Solution {
public:
    bool isSubsequence(string s, string t) {

        int sLength = s.length();
        int tLength = t.length();
        int i = 0;
        int j = 0;
        while(i < sLength && j < tLength){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        if(i >= sLength){
            return true;
        } else {
            return false;
        }
    }
};