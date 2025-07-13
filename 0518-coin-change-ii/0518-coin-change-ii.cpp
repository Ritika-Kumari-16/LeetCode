class Solution {
public:
int solve(int i , int n, int amount, vector<int>& coins,vector<vector<int>>&dp){
    // if(amount==0) return 1;
    if(i==n){
        if(amount!=0) return 0;
        return 1;
    }
    if(dp[i][amount]!=-1 ) return dp[i][amount];
    int take =0;
    if(coins[i]<=amount){
        take=solve(i,n,amount-coins[i],coins,dp);
    }
    int nottake= solve(i+1,n,amount,coins,dp);
    return dp[i][amount]= take + nottake ;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res=solve(0,n,amount,coins,dp);
        return res;
    }
};