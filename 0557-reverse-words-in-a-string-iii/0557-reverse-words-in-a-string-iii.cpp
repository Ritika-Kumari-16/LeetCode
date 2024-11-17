class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        while(i<s.size()){
            string temp="";
            while(i<s.size()&& s[i]!=' '){
                temp+=s[i];
                i++;
            }
            reverse(temp.begin(),temp.end());
            if(temp.size()>0){ans+=temp+' ';}
            i++;
        }
        ans.pop_back();
        return ans;
        
    }
};