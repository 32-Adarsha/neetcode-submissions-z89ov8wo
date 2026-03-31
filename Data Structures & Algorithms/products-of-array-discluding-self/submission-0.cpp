class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // two pass algorithm
        vector<int> result(nums.size() , 1);

        int pass = 1;
        for (int i = 0 ; i < nums.size() ; ++i){
            result[i] = pass;
            pass = pass * nums[i];
        }

        pass = 1;
        for (int i = nums.size()-1 ; i >=0 ; --i){
            result[i] = result[i] * pass;
            pass = nums[i] * pass;
        }

        return result;

    }
};
