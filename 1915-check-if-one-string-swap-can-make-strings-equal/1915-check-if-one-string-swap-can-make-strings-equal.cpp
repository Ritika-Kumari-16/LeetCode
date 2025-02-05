class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if( s1.size()!=s2.size()){
            return false;
        }
        int cnt=0;
        int i=0;
        int j=-1;
        int k=-1;
        while(i<s1.size()){
            if(s1[i]!=s2[i]){
                cnt++;
                if(j==-1){
                    j=i;
                }
                else if(k==-1){
                    k=i;
                }

            }
            i++;

    }
        if( cnt==0) return true;
        else if(cnt==2 && s1[j]==s2[k] && s1[k]==s2[j]) return true;
        return false;
    }
};