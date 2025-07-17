class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if (i == m - 1 && j == n - 1) continue;
                int up =0;
                if(i+1<=m-1){
                    up=dp[i+1][j];
                }
                int left=0;
                if(j+1<=n-1){
                    left=dp[i][j+1];
                }
                dp[i][j]=up+left;
            }
        }
        return dp[0][0];
    }
};

// class Solution {
// public:
// int solve( int i , int j , int n , int m , vector<vector<int>>&dp){
//     if(i==n-1 && j==m-1) return 1;
//     if(i>=n || j>=m) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int right= solve(i,j+1,n,m,dp);
//     int down= solve(i+1,j,n,m,dp);
//     return dp[i][j]=right+down;
// }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m ,vector<int>(n,-1));
//         return solve(0,0,m,n,dp); 
//     }
// };