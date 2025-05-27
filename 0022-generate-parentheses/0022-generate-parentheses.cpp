class Solution {
public:
    void solve ( int o , int c ,string &temp , vector<string>&result , int n){
        if(o == n && c== n){
            result.push_back(temp);
            return;
        }
        // take
        if(o<n){
            temp+="(";
            o++;
            solve(o,c,temp,result,n);
            temp.pop_back();
            o--;
        }
        if(c<o){
            temp+=")";
            c++;
            solve(o,c,temp,result,n);
            temp.pop_back();
            c--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string temp="";
        int c=0;
        int o=0;
        solve(o,c,temp,result,n);
        return result;
        
    }
};