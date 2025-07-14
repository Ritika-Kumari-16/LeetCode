class Solution {
public:
    int numDistinct(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
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