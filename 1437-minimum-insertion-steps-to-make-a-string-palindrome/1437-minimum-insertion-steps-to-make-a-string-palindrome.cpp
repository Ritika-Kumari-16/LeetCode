class Solution {
public:
    int minInsertions(string s) {
        string text1=s;
        reverse(s.begin(),s.end());
        string text2 = s;
        int n= text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][m]=0;
        }
        for(int j=0;j<=m;j++){
            dp[n][j]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return n-dp[0][0];
    }
};

// class Solution {
// public:
//     int solve( int i , int j , string s , string t, vector<vector<int>>&dp){
//         if(i<=0 || j<=0 ) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i-1]== t[j-1]) return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
//         int val = max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
//         return dp[i][j]= val;
//     }
//     int minInsertions(string s) {
//         int n= s.size();
//         string t;
//         for(int i=n-1;i>=0;i--){
//             t+=s[i];
//         }
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return n- solve(n,n,s,t,dp);
//     }
// };