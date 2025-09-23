class Solution {
public:
bool dfs(int i , int j , int k,string &word , vector<vector<char>>&board , vector<vector<int>>&visited){
    int n= board.size();
    int m=board[0].size();
    if(k==word.size()) return true;
    if(i < 0 || i>=n || j<0 ||j>=m || word[k]!=board[i][j] || visited[i][j]==1 ) return false;
    visited[i][j]=1;
    int drow[]={-1,0,0,1};
    int dcol[]={0,-1,1,0};
    for(int a=0;a<4;a++){
        int nrow=i+drow[a];
        int ncol=j+dcol[a];
        if(dfs(nrow,ncol,k+1,word,board,visited)) return true;
    }
    visited[i][j]=-1;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,word,board,visited)) return true;
                }
            }
        }
        return false;
    }
};