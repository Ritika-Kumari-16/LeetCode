class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
   sort(arr.begin(),arr.end());
    int n= arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int lastind=-1;
        int maxi=-1;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+ dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                lastind=i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            temp.push_back(arr[lastind]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};