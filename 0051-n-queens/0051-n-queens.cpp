class Solution {
public:
void generateboard(int col , int n ,vector<string>&board ,vector<vector<string>>&ans
, vector<int>lowerdiag, vector<int>&upperdiag ,vector<int>&rows){
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(rows[row]==-1 && lowerdiag[row+col]==-1 && upperdiag[(n-1)+(col-row)]==-1){
            board[row][col]='Q';
            rows[row]=1;
            lowerdiag[row+col]=1;
            upperdiag[(n-1)+(col-row)]=1;
            generateboard(col+1,n,board,ans,lowerdiag,upperdiag,rows);
            board[row][col]='.';
            rows[row]=-1;
            lowerdiag[row+col]=-1;
            upperdiag[(n-1)+(col-row)]=-1;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<int>lowerdiag(2*n-1,-1);
        vector<int>upperdiag(2*n-1,-1);
        vector<int>rows(n,-1);
        vector<vector<string>>ans;
        vector<string>board;
        string temp(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(temp);
        }
        generateboard(0,n,board,ans,lowerdiag,upperdiag,rows);
        return ans;
    }
};