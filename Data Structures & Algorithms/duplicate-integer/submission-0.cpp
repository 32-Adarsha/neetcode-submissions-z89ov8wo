class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int , bool> data;
        for (int i : nums) {
            if(data.find(i) != data.end()){
                return true;
            }

            data.insert({i , false});
        }

        return false;
    }
};