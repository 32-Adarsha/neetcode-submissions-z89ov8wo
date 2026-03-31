class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<vector<int>> result; 
       sort(nums.begin(), nums.end());
       findCombinationSum(nums , {} , 0 , target , result , 0);
       return result;
    }

    void findCombinationSum(vector<int>& nums, vector<int> combination , int sums , int target , vector<vector<int>>& result , int startIndex){
          for(int i = startIndex; i < nums.size() ; i++){
            combination.push_back(nums[i]);
            sums += nums[i];
            if(sums == target) {
                result.push_back(combination);
                return;
            } else if (sums > target) {
                return;
            }

            findCombinationSum(nums, combination , sums , target , result , i);
            sums -= nums[i];
            combination.pop_back();
          } 
    };
};