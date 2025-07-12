class Solution {
public:
int mod = 1e9+7;
    long long  pow_(long long x , long long n){
        long long result=1;
        while(n>0){
            if(n%2==0){
                x=(x*x)%mod;
                n=n/2;
            }
            else{
                result=(result*x)%mod;
                n=n-1;
            }
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long even= n/2+n%2;
        long long odd= n/2;
         long long res = (pow_(5, even) * pow_(4, odd)) % mod;
        return (int) res;
        
        
    }
};
