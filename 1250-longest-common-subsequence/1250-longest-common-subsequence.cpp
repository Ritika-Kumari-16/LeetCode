// class Solution {
// public:
//     int solve(int n , int m , string s1 , string s2, vector<vector<int>>&dp){
//         if(n<0||m<0) return 0;
//         if(dp[n][m]!=-1) return dp[n][m];
//         if(s1[n]==s2[m]) {return 1+ solve(n-1,m-1,s1,s2,dp);}
//         return dp[n][m]=max(solve(n-1,m,s1,s2,dp),solve(n,m-1,s1,s2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,text1,text2,dp);
        
//     }
// };
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.length(), 0);
        int longest = 0;

        for (char c : text2) {
            int curLength = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (curLength < dp[i]) {
                    curLength = dp[i];
                } else if (c == text1[i]) {
                    dp[i] = curLength + 1;
                    longest = max(longest, curLength + 1);
                }
            }
        }

        return longest;        
    }
};