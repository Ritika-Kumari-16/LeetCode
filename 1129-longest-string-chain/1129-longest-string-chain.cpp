class Solution {
public:
bool ispredecessor(string &word1 , string &word2){
    if(word1.size()==word2.size()) return false;
    int n= word1.size();
    int m= word2.size();
    if(m != (n+1)) return false;
    int i=0,j=0;
    while(i<n && j< m){
        if(word1[i] != word2[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    if((i==n && j==m ) || (i==n && j+1==m)) return true;
    return false;
}
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        vector<int>dp(n,1);
        int maxlen=1;
        sort(words.begin(),words.end(),[](const string& a , const string& b){
            return a.size()<b.size();
        });
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(ispredecessor(words[j],words[i]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
            }
        }
        return maxlen;
    }
};