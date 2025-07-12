class Solution {
public:
    bool solve(int row , int col , int i , vector<vector<char>>&board , string &word , vector<vector<int>>&visited){
        if(i==word.size()) return true;
        int n = board.size();
        int m= board[0].size();
        if(row<0 || row>=n || col<0 || col>=m || visited[row][col]==1 ||board[row][col]!=word[i] ) return false;
        visited[row][col]=1;
        bool found (solve(row-1,col,i+1,board,word,visited) 
                || solve(row,col-1,i+1,board,word,visited) 
                || solve(row,col+1,i+1,board,word,visited) 
                || solve(row+1,col,i+1,board,word,visited) );
        visited[row][col]=-1;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m= board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,0,board,word,visited)) return true;
                }
            }
        }
        return false;
    }
};