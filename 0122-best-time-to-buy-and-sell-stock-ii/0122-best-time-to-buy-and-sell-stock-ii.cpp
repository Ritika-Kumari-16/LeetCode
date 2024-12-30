class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2, 0); // Stores DP results for the next day
        vector<int> curr(2, 0); // Stores DP results for the current day

        // Traverse the prices array in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    // Option 1: Buy at current price and move to the next state
                    // Option 2: Skip buying
                    profit = max(-prices[i] + prev[0], prev[1]);
                } else {
                    // Option 1: Sell at current price and move to the next state
                    // Option 2: Skip selling
                    profit = max(prices[i] + prev[1], prev[0]);
                }
                curr[buy] = profit; // Update the current state
            }
            prev = curr; // Move to the next day
        }

        return prev[1]; // Maximum profit with buying allowed on the first day
    }
};



//memoization and recursion
// class Solution {
// public:
//     int solve(int ind, int buy, int n , vector<int>&prices , vector<vector<int>>&dp){
//         if(ind==n) return 0;
//         if(dp[ind][buy]!=-1) return dp[ind][buy];
//         int profit=0;
//         if(buy){
//             profit=max(-prices[ind]+solve(ind+1,0,n,prices,dp),0+solve(ind+1,1,n,prices,dp));
//         }
//         else{
//             profit=max(prices[ind]+solve(ind+1,1,n,prices,dp),0+solve(ind+1,0,n,prices,dp));
//         }
//         return dp[ind][buy]=profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return solve(0,1,n,prices,dp);
        
//     }
// };