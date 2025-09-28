class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
            if(target % coins[n-1] ==0){
                dp[n-1][target]=target/coins[n-1];
            }
            else{
                dp[n-1][target]=1e9;
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int target=0;target<=amount;target++){
                int take=1e9;
                if(coins[i]<=target){
                    take= 1+dp[i][target-coins[i]];
                }
                int nottake=dp[i+1][target];
                dp[i][target]=min(take,nottake);
            }
        }
        return dp[0][amount]>=1e9 ? -1: dp[0][amount];
    }
};

// class Solution {
// public:
// int noofcoins(int i , vector<int>&coins, int amount,vector<vector<int>>&dp){
//     int n= coins.size();
//     if(i==n){
//         if(amount==0) return 0;
//         return 1e9;
//     }
//     if(dp[i][amount]!=-1) return dp[i][amount];
//     int take=1e9;
//     if(coins[i]<=amount){
//         take=noofcoins(i,coins,amount-coins[i],dp);
//     }
//     int nottake= noofcoins(i+1,coins,amount,dp);
//     return dp[i][amount]=min(take+1,nottake);
// }
//     int coinChange(vector<int>& coins, int amount) {
//         int n= coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         int ans=noofcoins(0,coins,amount,dp);
//         return (ans>=1e9)? -1 : ans;
//     }
// };