class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>index(26,-1);
        vector<bool>seen(26,false);
        for(int i=0;i<s.size();i++){
            index[s[i]-'a']=i;
        }
        string result="";
        for(int i=0;i<s.size();i++){
            if(seen[s[i]-'a']==true){
                continue;
            }
            while(result.size()>0 && result.back()>s[i] && index[result.back()-'a']>i){
                seen[result.back()-'a']=false;
                result.pop_back();
            }
            result+=s[i];
            seen[s[i]-'a']=true;
                
            }
        
        return result;
        
    }
};