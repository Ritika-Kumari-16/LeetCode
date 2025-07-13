class Solution {
public:
int solve(int i , int n, int amount, vector<int>& coins,vector<vector<int>>&dp){
    if(i==n){
        if(amount!=0) return 1e9;
        return 0;
    }
    if(dp[i][amount]!=-1 ) return dp[i][amount];
    //take 
    int take =1e9;
    if(coins[i]<=amount){
        take=solve(i,n,amount-coins[i],coins,dp);
    }
    int nottake= solve(i+1,n,amount,coins,dp);
    return dp[i][amount]= min(1+take , nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res=solve(0,n,amount,coins,dp);
        return res>=1e9 ? -1:res;
        
    }
};