class Solution {
public:
bool solve(int i , int n , string &s , vector<string>&wordDict,unordered_set<string>&st,vector<int>&dp){
    if(i==n) return true;
    if(dp[i]!=-1) return dp[i];
    for(int idx=i;idx<n;idx++){
        string t=s.substr(i,idx-i+1);
        if(st.find(t)!=st.end() && solve(idx+1,n,s,wordDict,st,dp)){
            dp[i]=true;
            return true;
        }
    }
    return dp[i]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto &it : wordDict){
            st.insert(it);
        }
        vector<int>dp(s.size(),-1);
        return solve(0,s.size(),s,wordDict,st,dp);
        
    }
};