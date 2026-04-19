class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; 
        for(int i = digits.size()-1; i >= 0; --i){
            if((digits[i] + carry) < 10){
                digits[i] += carry;
                return digits ;
            }else{
                digits[i] =  0;
            }
        }

        vector<int> NewDigits(digits.size()+1 , 0);
        NewDigits[0] = 1; 
        return NewDigits;


    }
};
