class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[n-1]=matrix[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int leftdiag=INT_MAX;
                if(j-1>=0){
                    leftdiag=dp[i+1][j-1];
                }
                int rightdiag=INT_MAX;
                if(j+1<n){
                    rightdiag=dp[i+1][j+1];
                }
                int st=dp[i+1][j];
                dp[i][j]=matrix[i][j]+min(leftdiag,min(rightdiag,st));
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};


// class Solution {
// public:
// int solve(int i , int j , int n , vector<vector<int>>&matrix , vector<vector<int>>&dp){
//     if(j<0 || j>=n) return INT_MAX;
//     if(i==n-1){
//         return matrix[i][j];
//     }
//     if(dp[i][j]!=-1) return dp[i][j];
//     int diagleft=solve(i+1,j-1,n,matrix,dp);
//     int diagst=solve(i+1,j,n,matrix,dp);
//     int diagright=solve(i+1,j+1,n,matrix,dp);
//     return dp[i][j]= matrix[i][j]+min(diagleft , min( diagst , diagright));
// }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n= matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         int minisum=INT_MAX;
//         for(int i=0;i<n;i++){
//             minisum=min(minisum,solve(0,i,n,matrix,dp));
//         }
//         return minisum;
//     }
// };