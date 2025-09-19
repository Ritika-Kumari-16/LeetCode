class Solution {
public:
    bool checkValidString(string s) {
        int n= s.size();
        int maxcount=0, mincount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                maxcount++;
                mincount++;
            }
            else if(s[i]==')'){
                maxcount--;
                mincount--;
            }
            else{
                maxcount++;
                mincount--;
            }
            if(maxcount<0) return false;
            if(mincount<0) mincount=0;
        }
        return mincount==0;
    }
};