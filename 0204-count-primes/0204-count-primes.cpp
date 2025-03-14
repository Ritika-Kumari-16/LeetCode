class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<int>sieve(n+1,1);
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(sieve[i]==1){
                cnt++;
            }
        }
        return cnt;
        
    }
};