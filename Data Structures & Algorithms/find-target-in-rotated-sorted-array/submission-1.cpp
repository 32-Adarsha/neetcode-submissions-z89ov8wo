class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l = 0;
       int r = nums.size() - 1;


       while(l <= r){
        int m = (l + r) / 2;

        if (nums[m] == target) return m;

        // either left or right of mid

        if(nums[m] >= nums[l]){
            if(nums[l] <= target && target < nums[m]){
                r = m-1;
            } else {
                l = m+1;
            }
        } else  {
            if(nums[r] >= target && target > nums[m]){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }




       } 

       return -1;
    }
};
