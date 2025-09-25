class Solution {
public:
int possibleways(int i , int j, int m , int n){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    int right= possibleways(i,j+1,m,n);
    int down =possibleways(i+1,j,m,n);
    return right+down;
}
    int uniquePaths(int m, int n) {
        // return possibleways(0,0,m,n);
        vector<vector<int>>dp(m , vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int right=0;
                if(j+1<n){
                    right=dp[i][j+1];
                }
                int down=0;
                if(i+1<m){
                    down=dp[i+1][j];
                }
                dp[i][j]=right+down;
            }
        }
        return dp[0][0];
    }
};