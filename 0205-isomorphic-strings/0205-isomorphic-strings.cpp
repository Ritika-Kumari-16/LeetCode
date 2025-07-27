class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp;
        for(int i=0;i<s.size();i++){
            char s1=s[i];
            char t1=t[i];
            if(mpp.find(s1)!=mpp.end()){
                if(mpp[s1]!=t1) return false;
            }
            else{
                for(auto it:mpp){
                    if(it.second== t1){
                        return false;
                    }
                }
            }
            mpp[s1]=t1;
        }
        return true;
    }
};