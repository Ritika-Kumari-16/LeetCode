class Solution {
public:
    bool isvalid(int row, int col , int m , int n){
        return row<m && row>=0 && col>=0 && col<n;
    }
    int dfs (int row , int col , int m , int n , vector<vector<int>>&matrix,vector<vector<int>>& dp){
        int maxlen=1;
        if(dp[row][col]!=-1) return dp[row][col];
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            int nrow= row+delrow[i];
            int ncol= col+delcol[i];
            int top=0;
            if(isvalid(nrow,ncol,m,n) && matrix[row][col] < matrix[nrow][ncol] ){
                top = dfs(nrow,ncol,m,n,matrix,dp)+1;
                maxlen=max(maxlen,top);
            }

        }
        return dp[row][col]= maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int longinpath=0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i =0 ; i<m ; i++){
            for(int j=0;j<n;j++){
                longinpath= max(longinpath,dfs(i,j,m,n,matrix,dp));
            }
        }
        return longinpath;
    }
};