class Solution {
public:
    int solve1(int i,int j1, int j2, vector<vector<int>>& grid, int n, int m,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>=m || j2<0 ||j2>=m) return -1e9;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=0;
        for(int di= -1 ;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                if(j1==j2) {
                    maxi=max(maxi,grid[i][j1]+solve1(i+1,j1+di,j2+dj,grid,n,m,dp));
                }
                else{
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve1(i+1,j1+di,j2+dj,grid,n,m,dp));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int ans= solve1(0,0,m-1,grid,n,m,dp);
        return ans;
        
    }
};