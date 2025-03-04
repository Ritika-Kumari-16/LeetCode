class Solution {
public:
    bool ispalindrome(int i , int j ,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long mini= INT_MAX;
            for(int j= i;j<n;j++){
                if(ispalindrome(i,j,s)){
                    long long cost= 1+dp[j+1];
                    mini=min(mini,cost);}

            }
        dp[i]=mini;
        }
        return (int)dp[0]-1;
        
    }
};