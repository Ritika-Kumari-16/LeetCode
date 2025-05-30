class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        int n=s.size();
        reverse(t.begin(),t.end());
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];

                }
                else{
                    curr[j]= max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return n-prev[n];
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