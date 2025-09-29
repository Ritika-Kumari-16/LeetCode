class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for(int buy=1;buy>=0;buy--){
                if(buy%2==0){
                    dp[i][buy] =max(-prices[i] + dp[i + 1][1], dp[i +1][buy]); // buy skip
                }
                else{
                    dp[i][buy] =max((prices[i] -fee)+ dp[i + 1][0], dp[i + 1][buy]); // sell skip
                }
            }
        }
        return dp[0][0];
    }
};


// class Solution {
// public:
// int solve(int i , int buy ,int n , vector<int>&prices,vector<vector<int>>&dp,int fee){
//     if(i==n) return 0;
//     if(buy>=n) return 0;
//     if(dp[i][buy]!=-1) return dp[i][buy];
//     //buy
//     if(buy%2==0){
//         return dp[i][buy]=max(-prices[i] + solve(i+1,buy+1,n,prices,dp,fee) , solve(i+1,buy,n,prices,dp,fee));
//     }
//     //sell
//     else{
//         return dp[i][buy]=max((prices[i]-fee)+solve(i+1,buy+1,n,prices,dp,fee) , solve(i+1,buy,n,prices,dp,fee));
//     }
// }
//     int maxProfit(vector<int>& prices,int fee) {
//         int n = prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(n,-1));
//         return solve(0,0,n,prices,dp,fee);
        
//     }
// };