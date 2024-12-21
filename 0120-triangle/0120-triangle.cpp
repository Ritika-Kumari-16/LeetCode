class Solution {
public:
    int solve(int i , int j , vector<vector<int>>&triangle ,vector<vector<int>>&dp){
        if(i==triangle.size()-1){
            return triangle[triangle.size()-1][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int s=triangle[i][j]+solve(i+1,j,triangle,dp);
        int dg=triangle[i][j]+solve(i+1,j+1,triangle,dp);
        return dp[i][j]= min(s,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mini= solve(0,0,triangle,dp);
        return mini;
        
    }
};