class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&dp){

        if(m==0&&n==0) return 1;
        if(m>0 && n>0 && dp[m][n]!=-1) return dp[m][n];
        if(m<0||n<0) return 0;
        //up
        int up=0;
        if(m>0){up=solve(m-1,n,dp);}

        //left
        int left=0;
        if(n>0){left=solve(m,n-1,dp);}
        return dp[m][n]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) {dp[i][j]=1;}
                else{
                    int up=0,left=0;
                    if(i>0) {up=dp[i-1][j];}
                    if(j>0){ left=dp[i][j-1];}
                    dp[i][j]=left+up;

                }
            }
        }
        return dp[m-1][n-1];
    }
};