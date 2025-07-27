class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans;
        int j=0;
        int n= s.size();
        while(j<n){
            if(s[j]==' ') {
                j++;
                continue;
            }
            string temp;
            while(j<n && s[j]!=' ') {
                temp+=s[j];
                j++;
            }
            reverse(temp.begin(),temp.end());
            ans.append(temp + " ") ;
        }
        ans.pop_back();
        return ans;
    }
};