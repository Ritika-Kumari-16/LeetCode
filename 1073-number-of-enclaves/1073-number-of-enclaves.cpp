class Solution {
public:
void dfs(int row , int col , vector<vector<int>>&board , vector<vector<int>>&visited){
    visited[row][col]=1;
    int delrow[]={-1,0,0,1};
    int delcol[]={0,-1,1,0};
    int n= board.size();
    int m=board[0].size();
    for(int i=0;i<4;i++){
        int nrow=delrow[i]+row;
        int ncol=delcol[i]+col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]==1){
            dfs(nrow,ncol,board,visited);
        }
    }
}
    int numEnclaves(vector<vector<int>>& board) {
       int n =board.size();
        int m= board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]==1){
                dfs(0,i,board,visited);
            }
            if(board[n-1][i]==1){
                dfs(n-1,i,board,visited);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]==1){
                dfs(i,0,board,visited);
            }
            if(board[i][m-1]==1){
                dfs(i,m-1,board,visited);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1 && visited[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};