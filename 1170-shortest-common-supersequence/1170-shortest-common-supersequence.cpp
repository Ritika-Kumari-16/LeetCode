class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
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
        string ans;
        int i=0,j=0;
        while(i<n && j<m){
          if(text1[i]==text2[j]){
            ans.push_back(text1[i]);
            i++;
            j++;
          }
          else{
            if(dp[i+1][j] > dp[i][j+1]){
                ans.push_back(text1[i]);
                i=i+1;
            }
            else{
                ans.push_back(text2[j]);
                j=j+1;
              
            }
          }
        }
        while (i < n) ans.push_back(text1[i++]);
        while (j < m) ans.push_back(text2[j++]);
        return ans;
        
    }
};