class Solution {
public:
    int solve(int n , int m , string &w1, string &w2,vector<vector<int>>&dp){
        if(n<0&&m<0){return 0;}
        if(n<0) return m+1;
        if(m<0) return n+1;
        if(dp[n][m]!=-1) return dp[n][m];
        if(w1[n]==w2[m]) {
            return 0 + solve(n-1,m-1,w1,w2,dp);
        }
        return dp[n][m]=min(1+solve(n-1,m,w1,w2,dp),min(1+solve(n,m-1,w1,w2,dp),1+solve(n-1,m-1,w1,w2,dp)));
            }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m =word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2,dp);

        
    }
};