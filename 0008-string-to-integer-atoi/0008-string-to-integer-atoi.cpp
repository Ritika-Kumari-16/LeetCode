class Solution {
public:
    int myAtoi(string s) {
        int n= s.size();
        long result=0;
        int sign=1;
        int i=0;
        while(i<n && s[i]== ' '){
            i++;
        }
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+') {
            sign=1;
            i++;
        }
        while(i< n && isdigit(s[i])){
            result= result * 10 + (s[i]-'0');
            if(sign * result > INT_MAX) return INT_MAX;
            if(sign*result <INT_MIN) return INT_MIN;
            i++;
        }
        return sign*result;
    }
};