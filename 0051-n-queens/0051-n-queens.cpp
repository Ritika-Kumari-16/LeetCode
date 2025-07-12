class Solution {
public:
void solve( int col ,vector<string>&board , vector<vector<string>>&ans , int n,vector<int>&rowwise , vector<int>&diagonalleft , vector<int>&diagonalright){
    if(col== n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(rowwise[i]== 0 && diagonalright[i+col]==0 && diagonalleft[(n-1)+(col-i)]==0){
            board[i][col]='Q';
            rowwise[i]=1;
            diagonalright[i+col]=1;
            diagonalleft[(n-1)+(col-i)]=1;
            solve(col+1,board,ans,n,rowwise , diagonalleft, diagonalright);
            board[i][col]='.';
            rowwise[i]= 0;
            diagonalright[i+col]=0;
            diagonalleft[(n-1)+(col-i)]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board;
        string s(n,'.');
        vector<int>rowwise(n,0);
        vector<int>diagonalright(2*n-1,0);
        vector<int>diagonalleft(2*n-1,0);
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(0,board,ans,n,rowwise,diagonalleft,diagonalright);
        return ans;
    }
};