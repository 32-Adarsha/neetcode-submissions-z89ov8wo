class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> hash_map;
        for(int i =0 ; i < nums.size() ; i++){
            int otherHalf = target - nums[i];

            // if otherHalf is present in hash_map then we find i and j
            if(hash_map.find(otherHalf) != hash_map.end()){
                return {hash_map[otherHalf] , i};
            }


            // else
            hash_map.insert({nums[i] , i});

        }


        return {0 , 1};
    }
};
