class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r){
            int m = (l + r)/2;
            if(nums[l] <= nums[m] && nums[r] < nums[l]){
                cout<<nums[l]<<" "<<nums[m]<<" "<<nums[r]<<endl;
                l = m+1;
            } else {
                cout<<nums[l]<<" "<<nums[m]<<" "<<nums[r]<<endl;
                r = m;
            }
        }

        return nums[l];
    }
};
