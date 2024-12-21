class Solution{
    public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int st= matrix[i][j]+dp[i-1][j];
                int left=1e9;
                if(j>0){
                    left=matrix[i][j]+dp[i-1][j-1];
                }
                int right = 1e9;
                if(j<n-1){
                    right=matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j]=min(st,min(left,right));
            }
        }
        int mini= dp[n-1][0];
        for(int i=1;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }

};

// class Solution {
// public:
//     int solve(int i, int j,vector<vector<int>>&matrix , vector<vector<int>>&dp){
//         if(j<0 || j>matrix.size()-1) return 1e9;
//         if(i==matrix.size()-1) return matrix[matrix.size()-1][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int st= matrix[i][j]+solve(i+1,j,matrix,dp);
//         int left= matrix[i][j]+solve(i+1,j-1,matrix,dp);
//         int right= matrix[i][j]+solve(i+1,j+1,matrix,dp);
//         return dp[i][j]= min(st,min(left,right));

//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int mini=1e9;
//         int n= matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         for (int i=0;i<matrix.size();i++){
//             mini=min(mini,solve(0,i,matrix,dp));
//         }
//         return mini;
        
//     }
// };