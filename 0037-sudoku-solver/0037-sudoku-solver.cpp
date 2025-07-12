class Solution {
public:
bool valid(vector<vector<char>>& board ,int i , int j , char ch){
    for(int id=0;id<9;id++){
        if(board[id][j]==ch) return false;
        if(board[i][id]==ch) return false;
        if(board[3*(i/3)+id/3][3*(j/3)+id%3]==ch)return false;
    }
    return true;
}
bool solve(vector<vector<char>>&board){
        int n =9;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(valid(board,i,j,ch)){
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            board[i][j]='.';
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