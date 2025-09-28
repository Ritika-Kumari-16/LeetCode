class Solution {
public:
int noofcoins(int i , vector<int>&coins, int amount,vector<vector<int>>&dp){
    int n= coins.size();
    if(i==n){
        if(amount==0) return 0;
        return 1e9;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=1e9;
    if(coins[i]<=amount){
        take=noofcoins(i,coins,amount-coins[i],dp);
    }
    int nottake= noofcoins(i+1,coins,amount,dp);
    return dp[i][amount]=min(take+1,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=noofcoins(0,coins,amount,dp);
        return (ans>=1e9)? -1 : ans;
    }
};