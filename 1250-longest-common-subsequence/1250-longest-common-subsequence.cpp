class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        vector<int>dpprev(m+1,0);
        vector<int>dpcur(m+1,0);
        // for(int i=0;i<=n;i++){
        //     dp[i][m]=0;
        // }
        // for(int j=0;j<=m;j++){
        //     dp[n][j]=0;
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dpcur[j]=1+dpprev[j+1];
                }
                else{
                    dpcur[j]=max(dpprev[j],dpcur[j+1]);
                }
            }
            dpprev=dpcur;
        }
        return dpcur[0];
    }
};

// class Solution {
// public:
// int solve(int i , int j , int n , int m , string text1 , string text2 , vector<vector<int>>&dp){
//     if(i==n || j== m) return 0;
//     if(dp[i][j]!=-1 ) return dp[i][j];
//     //if found 
//     int found=0;
//     if(text1[i]==text2[j]){
//         found= 1+solve(i+1,j+1,n,m,text1,text2,dp);
//     }
//     else{
//         found= max(solve(i+1,j,n,m,text1,text2,dp),solve(i,j+1,n,m,text1,text2,dp));
//     }
//     return dp[i][j]= found;

// }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n= text1.size();
//         int m = text2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(0,0,n,m,text1,text2,dp);
        
//     }
// };