class Solution {
public:
unordered_map<char,char>mpp={
    {')' , '('} , { ']' , '['} , {'}', '{'}
};
    bool isValid(string s) {
        stack<char>st;
        for(int i=0 ;i<s.size();i++){
            if(s[i]== '(' || s[i]== '[' || s[i]== '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(mpp[s[i]] == st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }

        }
        return st.empty();
    }
};