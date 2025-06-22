class Solution {
public:
bool static comp ( const string &s1 ,const  string &s2){
    if(s1.size()==s2.size()) return s1<s2;
    return s1.size()<s2.size();
}
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        int i=0;
        string ans;
        string s1= strs[0];
        string s2= strs[n-1];
        while(i<s1.size()){
            if(s1[i]!=s2[i]) return ans;
            else{
                ans+=s1[i];
            }
            i++;
        }
        return ans;
    }
};