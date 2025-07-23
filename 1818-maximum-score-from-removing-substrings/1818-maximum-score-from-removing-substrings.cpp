class Solution {
public:
string deletestr(string s , string str){
    int i=0;
    for(int j=0;j<s.size();j++){
        s[i]=s[j];
        i++;
        if(i>=2 && s[i-2]==str[0] && s[i-1]==str[1]){
            i-=2;
        }
    }
    return s.substr(0,i);
}
    int maximumGain(string s, int x, int y) {
        string maxstr= x >=y ? "ab" : "ba";
        string minstr = x<y ? "ab" : "ba";
        string afterdelmax = deletestr(s,maxstr);
        int score=0;
        int len= s.size()-afterdelmax.size();
        score+=(len/2)*(max(x,y));
        string afterdelmin=deletestr(afterdelmax,minstr);
        len=afterdelmax.size()-afterdelmin.size();
        score+=(len/2)*(min(x,y));
        return score;
    }
};