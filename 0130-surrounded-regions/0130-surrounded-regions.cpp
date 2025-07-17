class Solution {
public:
void dfs(int i , int j ,  vector<vector<char>>&board ,vector<vector<int>>&visited ){
    visited[i][j]=1;
    int drow[]={-1,0,0,1};
    int dcol[]={0,-1,1,0};
    for(int k=0;k<4;k++){
        int nrow=i+drow[k];
        int ncol=j+dcol[k];
        if(nrow<0 || nrow>=board.size() || ncol<0 || ncol>=board[0].size() || visited[nrow][ncol] || board[nrow][ncol]=='X') continue;
        dfs(nrow,ncol,board,visited);
    }
}
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !visited[0][i]){
                dfs(0,i,board,visited);
            }
            if(board[n-1][i]=='O' && !visited[n-1][i]){
                dfs(n-1,i,board,visited);
            }
        }
        for(int j=0;j<n;j++){
            if(board[j][0]=='O'&& !visited[j][0]){
                dfs(j,0,board,visited);
            }
            if(board[j][m-1]=='O' && !visited[j][m-1]){
                dfs(j,m-1,board,visited);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};