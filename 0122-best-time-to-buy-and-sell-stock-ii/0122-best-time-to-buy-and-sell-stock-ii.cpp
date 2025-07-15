class Solution {
public:
int solve(int i , int buy ,int n , vector<int>&prices,vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    //buy
    if(buy==0){
        return dp[i][buy]=max(-prices[i] + solve(i+1,1,n,prices,dp) , solve(i+1,0,n,prices,dp));
    }
    //sell
    else{
        return dp[i][buy]=max(prices[i]+solve(i+1,0,n,prices,dp) , solve(i+1,1,n,prices,dp));
    }
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,0,n,prices,dp);
        
    }
};