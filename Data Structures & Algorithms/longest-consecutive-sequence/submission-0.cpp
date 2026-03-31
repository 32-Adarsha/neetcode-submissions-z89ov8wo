class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for(int num : nums){
            hash_set.insert(num);
        }

        int i = 0;
        int max_subseq = 0; 
        while (i < nums.size()){
            if(hash_set.find(nums[i]-1) == hash_set.end()){
                int count = 1;
                int start = nums[i] + 1;
                while(hash_set.find(start) != hash_set.end()){
                    count++;
                    start++;
                }
                

                max_subseq = max(max_subseq , count);
            }

            i++;
        }

        return max_subseq;
    }
};
