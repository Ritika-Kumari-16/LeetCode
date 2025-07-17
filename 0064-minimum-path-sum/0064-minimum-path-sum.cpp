class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if (i == m - 1 && j == n - 1) continue;
                int up =INT_MAX;
                if(i+1<=m-1){
                    up=dp[i+1][j];
                }
                int left=INT_MAX;
                if(j+1<=n-1){
                    left=dp[i][j+1];
                }
                dp[i][j]= grid[i][j]+min(up,left);
            }
        }
        return dp[0][0];
        
    }
};

// class Solution {
// public:
// int solve( int i , int j , int n , int m , vector<vector<int>>&grid , vector<vector<int>>&dp){
//     if(i==n-1 && j==m-1) return grid[n-1][m-1];
//     if(i>=n || j>=m) return INT_MAX;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int  right=  solve(i,j+1,n,m,grid,dp);
//     int down =solve(i+1,j,n,m,grid,dp);
//     return dp[i][j] = grid[i][j] + min(right,down);
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m= grid[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(0,0,n,m,grid,dp);
        
//     }
// };