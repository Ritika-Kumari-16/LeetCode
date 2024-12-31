class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2*k+1,0);
        vector<int>curr(2*k+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){
                    curr[trans] = max(
                        -prices[ind] + prev[ trans+1] ,
                        prev[ trans]
                    );
                }
                else{
                   curr[trans]=max(prices[ind]+prev[trans+1], prev[trans]);
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};


// //memoization
// class Solution {
// public:
//     int solve(int ind, int trans,int n , int k, vector<int>&prices, vector<vector<int>>&dp){
//         if(ind==n || trans==k) return 0;
//         if(dp[ind][trans]!=-1) return dp[ind][trans];
//         if(trans%2==0){
//             dp[ind][trans] = max(
//                 -prices[ind] + solve(ind + 1, trans + 1, n, k, prices, dp),
//                 solve(ind + 1, trans, n, k, prices, dp)
//             );
//         }
//         else{
//             dp[ind][trans]=max(prices[ind]+solve(ind+1,trans+1,n,k,prices,dp), solve(ind+1,trans,n,k,prices,dp));
//         }
//         return dp[ind][trans];
//     }
//     int maxProfit(int k,vector<int>& prices) {
//         int n= prices.size();
//         vector<vector<int>>dp(n,vector<int>(k*2,-1));
//         return solve(0,0,n,k*2,prices,dp);

//     }
// };