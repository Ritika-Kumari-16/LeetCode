class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int frst=INT_MAX;
                if(j-1>=0){
                    frst=dp[i-1][j-1];
                }
                int sec=INT_MAX;
                if(j<i){
                    sec=dp[i-1][j];
                }
                dp[i][j]=triangle[i][j]+min(frst,sec);
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());

    }
};

// class Solution {
// public:
// int solve( int i , int j , int n , vector<vector<int>>&triangle , vector<vector<int>>&dp){
//     if(i==n-1) return triangle[i][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     int onejump=triangle[i][j]+solve(i+1,j,n,triangle,dp);
//     int skip = triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
//     return dp[i][j]=min(onejump,skip);
// }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return solve(0,0,n,triangle,dp);
        
//     }
// };