class Solution {
public:
    string rotate(string &s){
        char temp=s[0];
        int n=s.size();
        for(int i=0;i<n-1;i++){
            s[i]=s[i+1];
        }
        s[n-1]=temp;
        return s;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        int n=s.size();
        for(int i=0;i<n;i++){
            rotate(s);
            if(s==goal){
                return true;
            }
        }
        return false;
        
    }
};