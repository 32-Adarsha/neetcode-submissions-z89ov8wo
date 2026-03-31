class Solution {
public:
    string longestPalindrome(string s) {
        int max_length = 0;
        string max_string = "";
        for(int i = 0 ; i < s.length() ; ++i){
            int left = i;
            int right = i;
            
            while(left >=0 && right < s.length() && s[left] == s[right]){
                if ((right - left + 1) > max_length) {
                    max_length = right - left +1;
                    max_string = s.substr(left , max_length);
                    cout<<max_string<<endl;
                } 
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                if(right-left+1 > max_length){
                    max_length = right - left + 1;
                    max_string = s.substr(left , max_length);
                }
                
                left--;
                right++;
            }

        }

        return max_string;

    }

};
