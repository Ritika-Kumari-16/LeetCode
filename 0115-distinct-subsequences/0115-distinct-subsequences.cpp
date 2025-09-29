class Solution {
public:
int count(int i, int j , string s , string p,vector<vector<double>>&dp){
    int n=s.size();
    int m= p.size();
    if(j==m) return 1;
    if(i==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j]){
        return dp[i][j]= count(i+1,j+1,s,p,dp)+count(i+1,j,s,p,dp);
    }
    return dp[i][j]= count(i+1,j,s,p,dp);
}
    int numDistinct(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        if(n<m) return 0;
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        // return count(0,0,text1,text2,dp);
        for(int i=0;i<=n;i++) dp[i][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }
    return (int)dp[0][0];
    }
};