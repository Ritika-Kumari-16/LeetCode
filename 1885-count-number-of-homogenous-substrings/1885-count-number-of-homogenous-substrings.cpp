class Solution {
public:
int MOD=1e9+7;
    int countHomogenous(string s) {
        int result=0;
        int leng=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            
            if( s[j]==s[i]){
                leng+=1;
            }
            else{
                i=j;
                leng=1;
            }
            result=(result+leng)%MOD;
        }
        return result ;
    }
};