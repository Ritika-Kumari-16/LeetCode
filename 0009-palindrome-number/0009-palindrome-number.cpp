class Solution {
public:
    bool isPalindrome(int x) {
        long long n =x;
        long long reversed=0;
        while(n>0){
            int digit =n%10;
            reversed=reversed*10+digit;
            n=n/10;
        }
        if(reversed==x){
            return true ;
        }
        else{
            return false;
        }
        
    }
};