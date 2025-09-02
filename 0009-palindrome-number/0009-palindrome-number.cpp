class Solution {
public:
    bool isPalindrome(int x) {
        int y= x;
        if(x<0) return false;
        long rev_val=0;
        while(y>0){
            int rem= y%10;
            rev_val= rev_val*10+rem;
            y=y/10;
        }
        rev_val= (int) rev_val;
        return x==rev_val;
    }
};