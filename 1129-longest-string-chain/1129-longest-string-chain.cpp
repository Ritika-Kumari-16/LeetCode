class Solution {
public:
bool ispredecessor(string word1 , string word2){
    int n= word1.size();
    int m = word2.size();
    if(n==m || n +1!=m) return false;
    int i=0,j=0;
    while(i<n && j<m){
        if(word1[i]!= word2[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    if(i == n && j== m) return true;
    if(i==n && j==m-1) return true;
    return false;



}
static bool comp(const string &a , const string &b){
    return a.size()<b.size();
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n= words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int previdx=0;previdx<i;previdx++){
                if(ispredecessor(words[previdx], words[i])){
                    dp[i]=max(dp[i],1+dp[previdx]);
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};