class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxi= INT_MIN;
            int maxel=INT_MIN;
            for(int j= i;j<min(n,i+k);j++){
                maxel=max(maxel,arr[j]);
                int val= maxel*(j-i+1)+dp[j+1];
                maxi=max(maxi,val);
                }
            dp[i]=maxi;
        }
        return dp[0];
    }
};