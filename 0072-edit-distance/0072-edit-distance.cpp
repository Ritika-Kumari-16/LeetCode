class Solution {
public:
int minop(int i , int j, string word1 , string word2 , vector<vector<int>>&dp){
    int n= word1.size();
    int m= word2.size();
    if(j==m){
        return n-i;
    }
    if(i==n){
        return m-j;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i]==word2[j]){
        return dp[i][j]= minop(i+1,j+1,word1,word2,dp);
    }
    else{
        int insert= 1+minop(i,j+1,word1,word2,dp);
        int del= 1+minop(i+1,j,word1,word2,dp);
        int rep=1+minop(i+1,j+1,word1,word2,dp);
        return min({insert, del , rep});
    }
}
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        // return minop(0,0,word1,word2,dp);
        for(int i=0;i<=n;i++){
            dp[i][m]=(n-i);
        }
        for(int i=0;i<=m;i++){
            dp[n][i]=(m-i);
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]=1+ min({dp[i+1][j+1], dp[i+1][j],dp[i][j+1]});
                }
            }
        }
        return dp[0][0];
    }
};