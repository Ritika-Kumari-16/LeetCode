class Solution {
public:
bool wordcheck(int i , string &s , unordered_set<string>&st,vector<int>&dp){
    if(i==s.size()) return true;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<s.size();j++){
        if(st.find(s.substr(i,j-i+1))!=st.end()){
            if(wordcheck(j+1,s,st,dp)) {
                dp[i]=true;
                return true;
            }
        }
    }
    return dp[i]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return wordcheck(0,s,st,dp);
    }
};