class Solution {
public:
    string replaceDigits(string s) {
        for(int i = 1 ; i < s.length(); i++){
            if(isdigit(s[i])){
                s[i] = s[i-1] + (s[i] - '0') ;
            }
        }
        return s;
    }
};