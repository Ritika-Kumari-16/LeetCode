class Solution {
public:
int noofcoins(int i , vector<int>&coins, int amount,vector<vector<int>>&dp){
    int n= coins.size();
    if(i==n-1){
        if(amount%coins[n-1]==0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=0;
    if(coins[i]<=amount){
        take=noofcoins(i,coins,amount-coins[i],dp);
    }
    int nottake= noofcoins(i+1,coins,amount,dp);

    return dp[i][amount]=(take+nottake);
}
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return noofcoins(0,coins,amount,dp);
    }
};