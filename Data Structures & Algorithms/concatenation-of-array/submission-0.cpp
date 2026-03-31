class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(2*nums.size());
        for(int i = 0 ; i < nums.size() ; i++){
            result[i] = nums[i];
            result[nums.size() + i ] = nums[i];
        }

        return result;
    }
};