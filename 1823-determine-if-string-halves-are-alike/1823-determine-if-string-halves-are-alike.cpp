class Solution {
public:
    unordered_set<char>st{'a' , 'e' , 'i' ,'o' , 'u', 'A', 'E','I', 'O' , 'U'};
    bool halvesAreAlike(string s) {
        int cnt1=0;
        int cnt2=0;
        int n= s.size()/2;
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end()){
                cnt1++;
            }
            if(st.find(s[n+i])!=st.end()){
                cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};