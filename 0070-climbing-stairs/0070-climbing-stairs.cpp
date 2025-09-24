class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int onesteps=dp[i-1];
            int twosteps=0;
            if(i-2>=0){
                twosteps=dp[i-2];
            }
            dp[i]=onesteps+twosteps;
        }
        return dp[n];
    }
};

// class Solution {
// public:
// int countways(int n , vector<int>&dp){
//     if(n==0) return 1;
//     if(n<0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     int onesteps=countways(n-1,dp);
//     int twosteps=countways(n-2,dp);
//     return dp[n]=onesteps+twosteps;
// }
//     int climbStairs(int n) {
//         vector<int>dp(n+1,-1);
//         return countways(n,dp);
//     }
// };