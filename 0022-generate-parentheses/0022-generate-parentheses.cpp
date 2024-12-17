class Solution {
public:
    void solve( int n, string &temp, vector<string> &result , int open, int close ){
        if(temp.size()==n*2 && close==open){
            result.push_back(temp);
            return ;
        }
        //taking (
        if(open <n){
            temp.push_back('(');
            open++;
            solve(n,temp,result,open,close);
            temp.pop_back();
            open--;
        }
        
        //taking )
        if(close <open){
            temp.push_back(')');
            close++;
            solve(n,temp,result,open,close);
            temp.pop_back();
            close--;
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string temp="";
        int open=0;
        int close=0;
        solve(n,temp,result,open , close);
        return result;
        
    }
};