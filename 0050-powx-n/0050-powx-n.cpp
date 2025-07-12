class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        double result=1;
        long long  m=n;
        if(m<0){
            m=-m;
        }
        while(m>0){
            //even power
            if(m%2 ==0 ){
                x=x*x;
                m=m/2;
            }
            else{
                //odd power 
                result*=x;
                m=m-1;
            }
        }

        return n>0 ? result : 1.0/result;
    }
};