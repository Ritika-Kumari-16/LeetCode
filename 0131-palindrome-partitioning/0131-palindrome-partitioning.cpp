class Solution {
public:
bool ispalindrome(string s , int i , int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve(int i , int n , string &s , vector<string>&temp , vector<vector<string>>&ans){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    for(int idx=i;idx<n;idx++){
        if(ispalindrome(s,i,idx)){
            temp.push_back(s.substr(i,idx-i+1));
            solve(idx+1,n,s,temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int n = s.size();
        vector<string>temp;
        solve(0,n,s,temp,ans);
        return ans;
        
    }
};