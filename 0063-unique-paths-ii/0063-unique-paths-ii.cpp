class Solution {
public:
    int solve(vector<vector<int>>&obs,vector<vector<int>>&dp,int n , int m){
        if(n>=0 && m>=0 && obs[n][m]==1) return 0;
        if(n==0 && m==0){ return 1;}
        if(n<0||m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=0;
        int left=0;
        if(n>0){up=solve(obs,dp,n-1,m);}
        if(m>0){left=solve(obs,dp,n,m-1);}
        return dp[n][m]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m =obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(obstacleGrid,dp,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0&&j==0) dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0){up=dp[i-1][j];}
                    if(j>0){
                        left=dp[i][j-1];

                    }
                    dp[i][j]=up+left;
                }

            }
        }
        return dp[n-1][m-1];

        
    }
};