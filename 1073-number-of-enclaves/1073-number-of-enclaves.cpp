class Solution {
public:
void dfs(int i , int j ,  vector<vector<int>>&board ,vector<vector<int>>&visited ){
    visited[i][j]=1;
    int drow[]={-1,0,0,1};
    int dcol[]={0,-1,1,0};
    for(int k=0;k<4;k++){
        int nrow=i+drow[k];
        int ncol=j+dcol[k];
        if(nrow<0 || nrow>=board.size() || ncol<0 || ncol>=board[0].size() || visited[nrow][ncol] || board[nrow][ncol]==0) continue;
        dfs(nrow,ncol,board,visited);
    }
}
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 1 && !visited[0][i]) {
                dfs(0, i, board, visited);
            }
            if (board[n - 1][i] == 1 && !visited[n - 1][i]) {
                dfs(n - 1, i, board, visited);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[j][0] == 1 && !visited[j][0]) {
                dfs(j, 0, board, visited);
            }
            if (board[j][m - 1] == 1 && !visited[j][m - 1]) {
                dfs(j, m - 1, board, visited);
            }
        }
        int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};