class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxprofit=0;
        int buystock=prices[0];
        for(int i=0;i<n;i++){
            if(buystock<prices[i]){
                maxprofit=max(maxprofit,prices[i]-buystock);
            }
            else if(buystock>prices[i]){
                buystock=prices[i];
            }
        }
        return maxprofit;
        
    }
};