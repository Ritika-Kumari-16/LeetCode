class Solution {
public:
bool match(int i , int j , string s , string p , vector<vector<int>>&dp){
    int n=s.size();
    int m=p.size();
    if(j==m){
        return i==n;
    }
    if(i==n){
        for(int k=j;k<m;k++){
            if(p[k]!='*') return 0;
        }
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j] || p[j]=='?'){
        return dp[i][j]=match(i+1,j+1,s,p,dp);
    }
    else if(p[j]!='*') return dp[i][j]=0;
    return dp[i][j]= (match(i,j+1,s,p,dp) || match(i+1,j,s,p,dp));
}
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n +1, vector<bool>(m +1, false));
        // return match(0,0,s,p,dp);
        dp[n][m]=true;
        for(int i=m-1;i>=0;i--){
            if(p[i]=='*') dp[n][i]=dp[n][i+1];
            else dp[n][i]=false;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==p[j] || p[j]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(p[j]!='*'){
                    dp[i][j]=false;
                }
                else{
                    dp[i][j]= (dp[i+1][j] || dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};