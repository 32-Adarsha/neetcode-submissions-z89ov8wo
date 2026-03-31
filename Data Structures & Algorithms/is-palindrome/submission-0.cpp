class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            // repeat until the character is no more space
            while(!isalnum(s[i]) && i < j){
                i++;
            }

            while(!isalnum(s[j]) && i < j) {
                j--;
            }

            

            if (i < j && tolower(s[i]) != tolower(s[j])){
                cout<<s[i]<<" "<<s[j]<<endl;
                return false;
            }
            
            i++;
            j--;
        }


        return true;
    }
};
