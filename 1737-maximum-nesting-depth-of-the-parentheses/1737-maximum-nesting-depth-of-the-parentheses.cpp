class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
                count=max(count,depth);
            }
            else if (s[i]==')'){
                depth--;
            }
        }
        return count;
    }
};