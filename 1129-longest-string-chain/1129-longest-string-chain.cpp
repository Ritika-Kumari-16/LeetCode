class Solution {
public:
    static bool comp(const string &s1,const string &s2){
        return s1.size()<s2.size();
    }
    bool checkpossible( string &s1 , string &s2){
        if(s1.size()-1!=s2.size()){
            return false;
        }
        int first=0;
        int second=0;
        while(first<s1.size()){
            if(second<s2.size()&& s1[first]==s2[second]){
                second++;
            }
                first++;
        }
        return second==s2.size();

    }
    int longestStrChain(vector<string>& arr) { 
        int n= arr.size();
        sort(arr.begin(),arr.end(),comp);
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkpossible(arr[i],arr[prev])&& 1+ dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};