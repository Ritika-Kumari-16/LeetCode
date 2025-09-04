//recursive
class Solution {
public:
bool ispali(string &s , int i , int n){
    if(i>=n) return true;
    if(!isalnum(s[i])) return ispali(s,i+1,n);
    if(!isalnum(s[n])) return ispali(s,i,n-1);
    if(tolower(s[i]) != tolower(s[n])) return false;
    return ispali(s,i+1,n-1);
}
    bool isPalindrome(string s) {
        int n= s.size()-1;
        return ispali(s,0,n);
    }
};
//iterative
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int i=0;
//         int n=s.size()-1;
//         while(i<=n){
//             if(!isalnum(s[i])){
//                 i++;
//                 continue;
//             }
//             if(!isalnum(s[n])){
//                 n--;
//                 continue;
//             }
//             if(tolower(s[i])!=tolower(s[n])) return false;
//             i++;
//             n--;
//         }
//         return true;
//     }
// };