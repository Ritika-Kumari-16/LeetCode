class Solution {
public:
bool isplaindrome(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void generatesub(int i , int n , string &s ,vector<string>&temp , vector<vector<string>>&ans ){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    for(int j=i;j<n;j++){
        if(isplaindrome(s.substr(i,j-i+1))){
            temp.push_back(s.substr(i,j-i+1));
            generatesub(j+1,n,s,temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        generatesub(0,s.size(),s,temp,ans);
        return ans;
    }
};