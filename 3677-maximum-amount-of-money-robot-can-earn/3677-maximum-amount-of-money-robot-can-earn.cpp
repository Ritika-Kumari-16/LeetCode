class Solution {
public:
    long long dp[501][501][3] ;
    bool visited[501][501][3] ;
    long long helper(int i , int j , int count , vector<vector<int>> &coins) {
        int n = coins.size() , m = coins[0].size() ;
        if( i == coins.size()-1 && j == coins[0].size()-1 ) {
            if( coins[i][j] < 0 && count > 0 ) return 0 ;
            return coins[i][j] ;
        }
        if( i >= coins.size() || j >= coins[0].size() ) return INT_MIN ;

        if( visited[i][j][count] ) return dp[i][j][count] ;
        
        long long right = INT_MIN , down = INT_MIN;

        
        right = coins[i][j] + helper(i , j+1 , count , coins) ;
        if( count > 0 && coins[i][j] < 0 ) {
            right = max(right , helper(i , j +1 , count-1 , coins)) ;
        }
        

        
        down = helper(i+1 , j , count , coins) + coins[i][j] ;
        if( count > 0 && coins[i][j] < 0 ) 
            down = max(down , helper(i+1 , j , count -1 , coins)) ;
        

        visited[i][j][count] = 1 ;
        return dp[i][j][count] = max(right , down) ;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp , -1 , sizeof(dp)) ;
        memset(visited , 0 , sizeof(visited)) ;
        return helper(0 , 0 , 2 , coins) ;
    }
};



// class Solution {
// public:
//     int solve( int i, int j,int n , int m, int k, vector<vector<int>>&coins , vector<vector<vector<int>>>& dp){
//         if(i==n-1 && j==m-1){
//             if(coins[i][j]>=0) return coins[i][j];
//             else if(k<2){
//                 return 0;
//             }
//             else{
//                 return coins[i][j];
//             }
//         }
//         if(dp[i][j][k]!=-1 ) return dp[i][j][k];
//         int maxcoins=INT_MIN;
//         //right
//         if(j+1<m){
//             if(coins[i][j+1]>=0){
//                 maxcoins =max(maxcoins,solve(i,j+1,n,m,k,coins,dp)+coins[i][j+1]);
//             }
//             else if(k<2){
                
//                 maxcoins=max(maxcoins,solve(i,j+1,n,m,k+1,coins,dp));
//             }
//             else{
//                 maxcoins=max(maxcoins,solve(i,j+1,n,m,k,coins,dp)+coins[i][j+1]);
//             }

//         }
//         //down
//         if(i+1<n){
//             if(coins[i+1][j]>=0){
//                 maxcoins =max(maxcoins,solve(i+1,j,n,m,k,coins,dp)+coins[i+1][j]);
//             }
//             else if(k<2){
                
//                 maxcoins=max(maxcoins,solve(i+1,j,n,m,k+1,coins,dp));
//             }
//             else{
//                 maxcoins=max(maxcoins,solve(i+1,j,n,m,k,coins,dp)+coins[i+1][j]);
//             }

//         }
//         return dp[i][j][k]=maxcoins;

//     }
//     int maximumAmount(vector<vector<int>>& coins) {
//         int n= coins.size();
//         int m = coins[0].size();
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
//         return solve(0,0,n,m,0,coins,dp);
        
//     }
// };



// class Solution {
// public:
//     int solve(int i, int j, int n, int m, vector<vector<int>>& coins, int used, vector<vector<vector<int>>>& dp) {
//         // Base Case: Reaching the bottom-right corner
//         if (i == n - 1 && j == m - 1) {
//             if (coins[i][j] >= 0) return coins[i][j];  // Positive coin
//             if (used < 2) return 0;                   // Neutralize robber
//             return coins[i][j];                       // Deduct coins for robber
//         }
        
//         // If already computed
//         if (dp[i][j][used] != -1) return dp[i][j][used];
        
//         int maxCoins = INT_MIN;

//         // Move Down
//         if (i + 1 < n) {
//             if (coins[i + 1][j] >= 0) {  // Positive coin
//                 maxCoins = max(maxCoins, solve(i + 1, j, n, m, coins, used, dp) + coins[i + 1][j]);
//             } else if (used < 2) {       // Neutralize robber
//                 maxCoins = max(maxCoins, solve(i + 1, j, n, m, coins, used + 1, dp));
//             } else {                     // Deduct coins for robber
//                 maxCoins = max(maxCoins, solve(i + 1, j, n, m, coins, used, dp) + coins[i + 1][j]);
//             }
//         }

//         // Move Right
//         if (j + 1 < m) {
//             if (coins[i][j + 1] >= 0) {  // Positive coin
//                 maxCoins = max(maxCoins, solve(i, j + 1, n, m, coins, used, dp) + coins[i][j + 1]);
//             } else if (used < 2) {       // Neutralize robber
//                 maxCoins = max(maxCoins, solve(i, j + 1, n, m, coins, used + 1, dp));
//             } else {                     // Deduct coins for robber
//                 maxCoins = max(maxCoins, solve(i, j + 1, n, m, coins, used, dp) + coins[i][j + 1]);
//             }
//         }

//         return dp[i][j][used] = maxCoins;  // Store and return result
//     }

//     int maximumAmount(vector<vector<int>>& coins) {
//         int n = coins.size();
//         int m = coins[0].size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));
//         return solve(0, 0, n, m, coins, 0, dp);
//     }
// };
