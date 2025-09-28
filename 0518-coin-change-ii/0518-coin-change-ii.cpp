class Solution {
public:
using u128 = unsigned __int128;
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
        vector<vector<u128>>dp(n,vector<u128>(amount+1,0));
        // return noofcoins(0,coins,amount,dp);
        for(int target=0; target<=amount;target++){
            if(target%coins[n-1]==0) dp[n-1][target]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int target=0;target<=amount;target++){
                u128  take=0;
                if(coins[i]<=target){
                    take= dp[i][target-coins[i]];
                }
                u128 nottake=dp[i+1][target];
                dp[i][target] = (take + nottake) ;
            }
        }
        return (int)dp[0][amount];
    }
};