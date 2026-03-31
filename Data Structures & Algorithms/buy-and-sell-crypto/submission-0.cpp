class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int mProfit = 0;
        while (j < prices.size()){
            if(prices[j] >= prices[i]){
                mProfit = max(prices[j] - prices[i] , mProfit);
                j++;
            } else {
                i = j;
                j = j+1;
            }
        }

        return mProfit;
        
    }
};
