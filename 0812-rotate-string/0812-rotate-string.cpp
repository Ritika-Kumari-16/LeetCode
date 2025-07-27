class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size() ) return false;
        string s1= s+s;
        int n= goal.size();
        for(int i=0;i<=s1.size()-n;i++){
            if(s1.substr(i,n)==goal) return true;
        }
        return false;
    }
};