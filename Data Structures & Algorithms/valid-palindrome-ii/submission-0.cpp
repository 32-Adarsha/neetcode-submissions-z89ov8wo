class Solution {
public:
    bool validPalindrome(string s) {
        return isValid(0 , s.size()-1,  s , 1);
    }


    bool isValid(int left , int right , string& s , int count){
        if(left >= right){
            return true;
        }


        if(s[left] == s[right]){
            left++;
            right--;
            return isValid(left , right , s , count);
        } else if ( count > 0 ){
            count--;
            return isValid(left+1 , right , s , count) || isValid(left , right-1 , s , count);
        }


        return false;

    }
};