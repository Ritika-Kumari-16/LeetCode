class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m]=true;
        for(int i=m-1;i>=0;i--){
            if(p[i]=='*'){
                dp[n][i]=dp[n][i+1];
            }
            else{
                break;
            }
        }

        for(int i= n-1 ;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==p[j] || p[j]=='?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    dp[i][j]=(dp[i][j+1] || dp[i+1][j+1] || dp[i+1][j]);
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[0][0];
    }
};