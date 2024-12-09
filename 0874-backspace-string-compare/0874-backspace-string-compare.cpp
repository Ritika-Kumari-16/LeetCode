class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string first="";
        string second="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
                first+=s[i];
            }
            else{
                if(!first.empty()){
                    first.pop_back();}
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]!='#'){
                second+=t[i];
            }
            else{
                if(!second.empty()){
                    second.pop_back();}
            }
        }
        if(first==second) return true;
        return false;
        
    }
};