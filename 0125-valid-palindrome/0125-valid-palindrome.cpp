class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int n=s.size()-1;
        while(i<=n){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[n])){
                n--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[n])) return false;
            i++;
            n--;
        }
        return true;
    }
};