class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size() - 1;    
        int start = 0;
        while(start <= last){
            if (nums[start] == val) {
                swap(nums[start] , nums[last]);
                last--;
            }else{
                start++;
            } 
        }

        return last + 1;
    }
};