class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num=0;
        for(int i=1;i<=n;i++){
            if(i%m==0){
                num-=i;
            }
            else{
                num+=i;
            }
        }
        return num;
    }
};
// class Solution {
// public:
//     int differenceOfSums(int n, int m) {
//         int k = n / m;
//         return n * (n + 1) / 2 - k * (k + 1) * m;
//     }
// };