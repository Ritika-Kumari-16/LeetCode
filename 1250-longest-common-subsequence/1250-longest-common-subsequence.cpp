class Solution {
public:
int findlength(int i , int j , string &s1 , string &s2,vector<vector<int>>&dp){
    int n= s1.size();
    int m= s2.size();
    if(i==n || j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=1+findlength(i+1,j+1,s1,s2,dp);
    }
    int leftpt= findlength(i+1,j,s1,s2,dp);
    int rightpt=findlength(i,j+1,s1,s2,dp);
    return dp[i][j]=max(leftpt,rightpt);
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return findlength(0,0,text1,text2,dp);
        // for(int i=0;i<n;i++){
        //     if(text1[i]==text2[m-1]){
        //         dp[i][m-1]=1;
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     if(text2[i]==text1[n-1]){
        //         dp[n-1][i]=1;
        //     }
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};