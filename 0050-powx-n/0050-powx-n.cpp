class Solution {
public:
double findans(double x , long long n){
    if(n==0) return 1;
    if(n%2==0 ) {
        return findans(x*x , n/2);
    }
    return x * findans(x,n-1);
}
    double myPow(double x, int n) {
        long long m= n;
        if(n<0){
            m=m*-1;
        }
        double ans=findans(x,m);
        return (n<0) ? 1/ans : ans;
    }
};

// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long m=n;
//         if(n<0){
//             m=m*-1;
//         }
//         double ans=1;
//         while(m>0){
//             if(m%2==0){
//                 x=x*x;
//                 m=m/2;
//             }
//             else{
//                 ans*=x;
//                 m=m-1;
//             }
//         }
//         if(n<0) return (double) 1/ ans;
//         return ans;
//     }
// };