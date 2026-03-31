class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> result;  
       result.push_back(0);
       if(n == 0) return result;
       result.push_back(1);
       if(n == 1) return result;
       int count = 0;
       for(int i = 2; i <= n ; ++i){
           if(!(i & (i - 1))){
                count = 0 ;
           }
           result.push_back(1 + result[count]);
           count++;
       }
       return result;
    }
};
