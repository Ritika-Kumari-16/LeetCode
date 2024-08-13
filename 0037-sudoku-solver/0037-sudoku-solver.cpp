class Solution {
public:
    bool ispossible(vector<vector<char>>&board , int i, int j, char c){
        for(int r=0;r<9;r++){
            if(board[i][r]==c) return false;
            if(board[r][j]==c) return false;
            if(board[3*(i/3)+r/3][3*(j/3)+r%3]==c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        for (int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(ispossible(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)==true){
                            return true;}
                            else {
                            board[i][j]='.';}
                        }
                    }
                    return false;

                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};