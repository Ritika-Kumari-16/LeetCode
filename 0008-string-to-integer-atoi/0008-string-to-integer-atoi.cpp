class Solution {
public:
    int myAtoi(string s) {
        int n= s.size();
        int i=0;
        long long result=0;
        int sign=1;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]== '+')i++;
        while(i<n && isdigit(s[i])){
            result=(result*10) +(s[i]-'0');
            i++;
            if(sign* result < INT_MIN) return INT_MIN;
            if(sign* result> INT_MAX) return INT_MAX;
        }
        return (int)sign*result;
    }
};