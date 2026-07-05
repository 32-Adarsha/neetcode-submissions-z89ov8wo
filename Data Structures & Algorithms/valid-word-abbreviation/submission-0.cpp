#include <string>
#include <cctype> // Required for isdigit()

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int n = word.length();
        int m = abbr.length();
        
        while (i < n && j < m) {
            // Case 1: If it's a digit, parse the full number
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false; // No leading zeros
                
                int len = 0;
                while (j < m && isdigit(abbr[j])) {
                    len = (len * 10) + (abbr[j] - '0');
                    j++;
                }
                i += len; // Skip characters in the word
            } 
            // Case 2: It's a character, must match
            else {
                if (word[i] != abbr[j]) return false;
                i++;
                j++;
            }
        }
        
        // Both strings must be fully consumed
        return i == n && j == m;
    }
};