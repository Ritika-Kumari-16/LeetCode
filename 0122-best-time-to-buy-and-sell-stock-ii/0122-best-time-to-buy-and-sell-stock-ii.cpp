class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    int take= -prices[i]+dp[i+1][1];
                    int nottake= dp[i+1][0];
                    dp[i][j]=max(take,nottake);
                }
                else{
                    int take= prices[i]+dp[i+1][0];
                    int nottake=dp[i+1][1];
                    dp[i][j]=max(take,nottake);
                }
            }
        }
        return dp[0][0];
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2, 0));
//         for (int i = n - 1; i >= 0; i--) {
//             dp[i][0] =
//                 max(-prices[i] + dp[i + 1][1], dp[i + 1][0]); // buy skip

//             dp[i][1] =
//                 max(prices[i] + dp[i + 1][0], dp[i + 1][1]); // sell skip
//         }
//         return dp[0][0];
//     }
// };

// class Solution {
// public:
// int solve(int i , int buy ,int n ,
// vector<int>&prices,vector<vector<int>>&dp){
//     if(i==n) return 0;
//     if(dp[i][buy]!=-1) return dp[i][buy];
//     //buy
//     if(buy==0){
//         return dp[i][buy]=max(-prices[i] + solve(i+1,1,n,prices,dp) ,
//         solve(i+1,0,n,prices,dp));
//     }
//     //sell
//     else{
//         return dp[i][buy]=max(prices[i]+solve(i+1,0,n,prices,dp) ,

//         solve(i+1,1,n,prices,dp));
//     }
// }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>>dp(n,vector<int>(2,-1));
//         return solve(0,0,n,prices,dp);

//     }
// };