// memoization and recursion
class Solution {
public:
    int solve(int ind, int buy, int n , vector<int>&prices , vector<vector<int>>&dp, int fee){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(ind+1,0,n,prices,dp,fee),0+solve(ind+1,1,n,prices,dp,fee));
        }
        else{
            profit=max(prices[ind]-fee+solve(ind+1,1,n,prices,dp,fee),0+solve(ind+1,0,n,prices,dp,fee));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,n,prices,dp,fee);
        
    }
};