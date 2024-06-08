class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxprofit=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            buy=min(buy,prices[i]);
            int profit=prices[i]-buy;
            mxprofit=max(mxprofit,profit);

        }
        return mxprofit;
        
    }
};