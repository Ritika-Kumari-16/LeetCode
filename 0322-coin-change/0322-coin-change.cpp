class Solution {
public:
    int solve(int n , vector<int>&coins , int amount ,vector<vector<int>>&dp){
        if(n==0){
            return dp[n][amount]=(amount%coins[n]==0)?amount/coins[n] : 1e9;
        }
        //take
        if(dp[n][amount]!=-1) return dp[n][amount];
        int take=INT_MAX;
        if(amount>=coins[n]){
        take=1+solve(n,coins,amount-coins[n],dp);
        }
        int nottake=0+solve(n-1,coins,amount,dp);
        return dp[n][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,dp);
        return ans>=1e9?-1 :ans;

        
    }
};