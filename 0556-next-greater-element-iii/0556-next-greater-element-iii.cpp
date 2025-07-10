class Solution {
public:
    int nextGreaterElement(int n) {
        string s= to_string (n);
        int m= s.size();
        int brkpt=-1;
        for(int i=m-2;i>=0;i--){
            if(s[i]<s[i+1]){
                brkpt=i;
                break;
            }
        }
        if(brkpt == -1) return -1;
        for(int i=m-1;i>brkpt;i--){
            if(s[i]>s[brkpt]){
                swap(s[i],s[brkpt]);
                break;
            }
        }
        sort(s.begin()+brkpt+1, s.end());
        long long nw= stoll(s);
        if(nw>INT_MAX) return -1;
        return (int)nw;
    }
};