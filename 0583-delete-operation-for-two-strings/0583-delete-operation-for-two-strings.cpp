class Solution {
public:
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<m;i++) dp[n][i]=(m-i);
        for(int i=0;i<n;i++) dp[i][m]=(n-i);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]= 1 + min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};

// class Solution {
// public:
//     int solve( int i , int j, string word1 , string word2 , vector<vector<int>>&dp){
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(word1[i]==word2[j]){
//             return dp[i][j]=solve(i-1, j-1 , word1, word2, dp);
//         } 
//         else{
            
//             return  min(1+ solve(i-1,j,word1,word2,dp),1+solve(i,j-1,word1,word2,dp));
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int n= word1.size();
//         int m= word2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,word1,word2,dp);
        
//     }
// };