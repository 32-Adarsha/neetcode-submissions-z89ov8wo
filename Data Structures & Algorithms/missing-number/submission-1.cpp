
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size()+1;
        int sum  = s * (s-1)/2; 
    
        for(auto i : nums){
            
            sum -= i;
        }
        return sum;
    }
};
