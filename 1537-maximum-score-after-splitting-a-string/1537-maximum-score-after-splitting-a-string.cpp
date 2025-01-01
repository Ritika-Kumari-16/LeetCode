class Solution {
public:
    int maxScore(string s) {
        int n= s.size();
        int score=INT_MIN;
        int left_zeros=0;
        int left_ones=0;
        int right_ones=0;
        int total=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                total++;
            }
        }
        for(int i=0;i<=n-2;i++){
            if(s[i]=='1') left_ones++;
            else{
                left_zeros++;
            }
            right_ones=total-left_ones;
            score=max(score,left_zeros+right_ones);
        }
        return score;
        
    }
};


// class Solution {
// public:
//     int maxScore(string s) {
//         int n=s.size();
//         int score= INT_MIN;
//         int ones=0;
//         int zeros=0;
//         for(int i=0;i<=n-2;i++){
//             if(s[i]=='0'){
//                 zeros++;
//             }
//             else {ones++ ;}
//             score=max(score,zeros-ones);
//         }
//         if(s[n-1]=='1') ones++;
//         return score+ones;
        
//     }
// };