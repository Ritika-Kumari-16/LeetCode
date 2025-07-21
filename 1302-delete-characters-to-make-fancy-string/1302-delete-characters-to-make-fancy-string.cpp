class Solution {
public:
    string makeFancyString(string s) {
        int n= s.size();
        string ans;
        for(int i=0;i<s.size();i++){
            if( (i+2<n && s[i]==s[i+1] && s[i]==s[i+2])){
                continue;
            }
            else if(n-i<2 ){
                ans+=s[i];
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};