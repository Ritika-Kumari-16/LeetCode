class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+2,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            dp[i]=dp[i+1]+dp[i+2];
        }
        return dp[0];
    }
};

// class Solution {
// public:
// int solve(int i , int n,vector<int>&dp){
//     if(i==n) return 1;
//     if(i>n) return 0;
//     if(dp[i]!=-1) return dp[i];
//     //one step 
//     int onestep=solve(i+1,n,dp);
//     int twosteps=solve(i+2,n,dp);
//     return dp[i]=onestep+twosteps;
// }
//     int climbStairs(int n) {
//         vector<int>dp(n+1,-1);
//         return solve (0,n,dp);
        
//     }
// };