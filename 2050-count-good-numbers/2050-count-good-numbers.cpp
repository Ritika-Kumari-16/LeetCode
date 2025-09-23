class Solution {
public:
int mod=1e9+7;
long long findpow(long long x, long long n) {
        long long m=n;
        if(n<0){
            m=m*-1;
        }
        long long ans=1;
        while(m>0){
            if(m%2==0){
                x=(x*x)%mod;
                m=m/2;
            }
            else{
                ans=(ans*x)%mod;
                m=m-1;
            }
        }
        if(n<0) return (long long) 1/ ans;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long oddidx=n/2;
        long long evenidx= oddidx+(n%2);
        long long ans= (findpow(5,evenidx )* findpow(4,oddidx))%mod;
        return (int)ans;
    }
};