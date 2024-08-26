// class Solution {
// public:
//     // int solve(int ind , int n, vector<int>&cuts,vector<vector<int>>&dp){
//     //     if(ind==0){
//     //         return n*cuts[0];
//     //     }
//     //     if(dp[ind][n]!=-1) return dp[ind][n];
//     //     int nottake = 0 + solve(ind-1,n,cuts,dp);
//     //     int take=INT_MAX;
//     //     if(ind+1<=n){
//     //         take = cuts[ind] + solve(ind,n-(ind+1),cuts,dp);
//     //     }
//     //     return dp[ind][n]=min(take,nottake);
//     // }

//     int minCost(int n, vector<int>& cuts) {
//         int m=cuts.size();
//         vector<vector<int>>dp(m,vector<int>(n+1,-1));
//         return solve(m-1,n,cuts,dp);
        
//     }
// };

class Solution {
public:
    int dp[101][101];
    
    int mincost(int start, int end, vector<int>& cuts, int cuts_start, int cuts_end)
    {
        if(cuts_start>cuts_end)
            return 0;
        
        if(dp[cuts_start][cuts_end]!=-1)
            return dp[cuts_start][cuts_end];
        
        int minimum = INT_MAX;
        for(int i=cuts_start; i<=cuts_end; i++)
            minimum = min(minimum, (end-start)+mincost(start, cuts[i], cuts, cuts_start, i-1)+mincost(cuts[i], end, cuts, i+1, cuts_end));
        
        return dp[cuts_start][cuts_end] = minimum;
    }
    
    int minCost(int n, vector<int>& cuts) {

        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return mincost(0, n, cuts, 0, cuts.size()-1);
    }
};