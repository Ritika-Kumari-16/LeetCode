// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         stack<char>st;
//         string ans="";
//         int n= s.size();
//         for(int i=0;i<n;i++){
//             if(st.empty()){
//                 st.push(s[i]);
//             }
//             else{
//                 if(s[i]=='('){
//                     st.push(s[i]);
//                     ans+=s[i];
//                 }
//                 else{
//                     st.pop();
//                     if(!st.empty()){
//                         ans+=s[i];
//                     }
//                 }
//             }
//         }
//         return ans;
        
//     }
// };

#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;  // Track the depth of nested parentheses

        for (char c : s) {
            if (c == '(') {
                // Only add to result if it's not an outermost '('
                if (depth > 0) {
                    ans += c;
                }
                depth++;
            } else {
                depth--;
                // Only add to result if it's not an outermost ')'
                if (depth > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};
