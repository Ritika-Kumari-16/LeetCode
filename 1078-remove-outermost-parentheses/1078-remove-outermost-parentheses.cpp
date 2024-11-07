class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        int n= s.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='('){
                    st.push(s[i]);
                    ans+=s[i];
                }
                else{
                    st.pop();
                    if(!st.empty()){
                        ans+=s[i];
                    }
                }
            }
        }
        return ans;
        
    }
};