class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if (obstacleGrid[0][0]==1 ||obstacleGrid[m-1][n-1] == 1)
            return 0;// Destination is blocked
        vector<vector<long long>>dp(m,vector<long long>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if((i==m-1&& j==n-1) || obstacleGrid[i][j]==1) continue;
                long long right=0;
                if(j+1<n){
                    right=dp[i][j+1];
                }
                long long down=0;
                if(i+1<m){
                    down=dp[i+1][j];
                }
                dp[i][j]=right+down;
            }
        }
        return dp[0][0];
    }
};


// class Solution {
// public:
// int solve( int i , int j , int n , int m , vector<vector<int>>&grid,vector<vector<int>>&dp){
//     if(i==n-1 && j==m-1) return 1;
//     if(i>=n || j>=m || grid[i][j]==1) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int right= solve(i,j+1,n,m,grid,dp);
//     int down= solve(i+1,j,n,m,grid,dp);
//     return dp[i][j]=right+down;
// }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
//         vector<vector<int>>dp(n ,vector<int>(m,-1));
//         return solve(0,0,n,m,obstacleGrid,dp); 
        
//     }
// };