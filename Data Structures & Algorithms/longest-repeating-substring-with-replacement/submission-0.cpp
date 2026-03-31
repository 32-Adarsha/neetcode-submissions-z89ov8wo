class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> char_count(26 , 0);
        int max_char = 0;

        int i = 0;
        int j = 0;

        while (j < s.length()){
            char_count[s[j] - 'A']++;
            max_char = max(max_char , char_count[s[j] - 'A']);
            int window = j - i + 1;
            if (window - max_char > k){
                char_count[s[i] - 'A']--;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return j-i;
    }
};
