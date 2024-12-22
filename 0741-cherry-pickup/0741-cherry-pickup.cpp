class Solution {
public:
    int solve( int i1, int j1, int i2, int j2 , int n, int m , vector<vector<int>>& grid, int dp[50][50][50][50]){
        if(i1>=n || i2>=n || j1>=m ||j2>=m || grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e8;
        if(i1==n-1 && j1==m-1) return grid[i1][j1];
        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        int cherries=0;
        if(i1==i2 && j1==j2){
            cherries+=grid[i1][j1];
        }
        else{
            cherries+=grid[i1][j1]+grid[i2][j2];
        }
         int f1=solve(i1+1,j1,i2+1,j2,n,m,grid,dp);
         int f2= solve(i1,j1+1,i2,j2+1,n,m,grid,dp);
         int f3 = solve(i1+1,j1,i2,j2+1,n,m,grid,dp);
         int f4 = solve(i1,j1+1,i2+1,j2,n,m,grid,dp);
         cherries+=max(max(f1,f2),max(f3,f4));
         return dp[i1][j1][i2][j2]=cherries;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int dp[50][50][50][50];
        memset(dp,-1,sizeof(dp));
        int maxi=solve(0,0,0,0,n,m,grid,dp);
        return max(maxi,0);
        
    }
};