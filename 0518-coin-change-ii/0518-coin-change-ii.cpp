class Solution {
public:
    // The way in which we compute the tabulation changes the solution efficiency.
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        
        for(int coin = n - 1;coin >=0;coin--){
            for(int target = 0;target <= amount;target++){
                if(target >= coins[coin]){
                    dp[target] += dp[target - coins[coin]];
                }
            }
        }
        return dp[amount];
    }
};

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         if(n==0) return 0;
//         vector<vector< long long>>dp(n,vector<long long>(amount+1,0));
//         for(long long t=0;t<=amount;t++){
//             if(t%coins[0]==0) dp[0][t]=1;
//         }
//         for(long long i=1;i<n;i++){
//             for(long long t=0;t<=amount;t++){
//                 long long nottake= dp[i-1][t];
//                 long long take=0;
//                 if(coins[i]<=t){
//                     take=dp[i][t-coins[i]];
//                 }
//                 dp[i][t]= take+nottake;
//             }
//         }
//         return dp[n-1][amount];
//     }
// };



// class Solution {
// public:
//     int solve(int i,vector<int>& coins , int amount, vector<vector<int>>&dp ){
//         if(i==0) {
//             if(amount%coins[0]==0) return 1;
//             return 0;
//         }
//         if(dp[i][amount]!=-1) return dp[i][amount];
//         int nottake= solve(i-1,coins,amount,dp);
//         int take=0;
//         if(coins[i]<=amount){
//             take=solve(i,coins,amount-coins[i],dp);
//         }
//         return dp[i][amount]= take+nottake;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n= coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         return solve ( n-1,coins,amount,dp);
        
//     }
// };