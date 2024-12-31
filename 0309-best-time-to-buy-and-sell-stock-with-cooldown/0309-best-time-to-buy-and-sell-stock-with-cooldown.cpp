class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2, 0));
        // Traverse the prices array in reverse order
        for (int i = n - 1; i >= 0; i--) {

                    dp[i][1]= max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                    dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
                }// Update the current state

        return dp[0][1]; // Maximum profit with buying allowed on the first day
    }
};

// // memoization and recursion
// class Solution {
// public:
//     int solve(int ind, int buy, int n , vector<int>&prices , vector<vector<int>>&dp){
//         if(ind>=n) return 0;
//         if(dp[ind][buy]!=-1){ return dp[ind][buy];}
//         int profit=0;
//         if(buy){
//             profit=max(-prices[ind]+solve(ind+1,0,n,prices,dp),solve(ind+1,1,n,prices,dp));
//         }
//         else{
//             profit=max(prices[ind]+solve(ind+2,1,n,prices,dp),solve(ind+1,0,n,prices,dp));
//         }
//         return dp[ind][buy]=profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return solve(0,1,n,prices,dp);
        
//     }
// };