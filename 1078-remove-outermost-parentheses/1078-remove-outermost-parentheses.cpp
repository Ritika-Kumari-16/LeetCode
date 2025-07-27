class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int open=0;
        for(auto &ch : s){
            if(ch=='(') {
                if(open==0){
                    open++;
                }
                else{
                    ans+=ch;
                    open++;
                }
            }
            else{
                if(open==1){
                    open--;
                }
                else{
                    ans+=ch;
                    open--;
                }
            }

        }
        return ans;
    }
};