class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[n-1]=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// class Solution {
// public:
// int solve( int i , int j , int n , vector<vector<int>>&triangle , vector<vector<int>>&dp){
//     if(i==n-1) return triangle[i][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     int onejump=triangle[i][j]+solve(i+1,j,n,triangle,dp);
//     int skip = triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
//     return dp[i][j]=min(onejump,skip);
// }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return solve(0,0,n,triangle,dp);
        
//     }
// };