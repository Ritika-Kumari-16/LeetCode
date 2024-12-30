class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Initialize DP tables for the current and previous day
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        // Traverse prices in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if (buy) {
                        // Either buy at the current price or skip buying
                        profit = max(-prices[i] + prev[0][cap], prev[1][cap]);
                    } else {
                        // Either sell at the current price or skip selling
                        profit = max(prices[i] + prev[1][cap - 1], prev[0][cap]);
                    }
                    curr[buy][cap] = profit; // Update the current state
                }
            }
            prev = curr; // Move to the next day
        }

        return prev[1][2]; // Maximum profit with up to 2 transactions and buying allowed
    }
};


// // memoization and recursion
// class Solution {
// public:
//     int solve(int ind, int buy, int cap,int n , vector<int>&prices , vector<vector<vector<int>>>&dp){
//         if(cap==0) return 0;
//         if(ind==n) return 0;
//         if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
//         int profit=0;
//         if(buy){
//             profit=max(-prices[ind]+solve(ind+1,0,cap,n,prices,dp),0+solve(ind+1,1,cap,n,prices,dp));
//         }
//         else{
//             profit=max(prices[ind]+solve(ind+1,1,cap-1,n,prices,dp),0+solve(ind+1,0,cap,n,prices,dp));
//         }
//         return dp[ind][buy][cap]=profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
//         return solve(0,1,2,n,prices,dp);
        
//     }
// };