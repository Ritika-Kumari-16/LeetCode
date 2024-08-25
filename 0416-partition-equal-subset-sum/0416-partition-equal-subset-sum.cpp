class Solution {
public:
    bool f(int n,vector<int> &arr, int sum,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(n==0) return (arr[n]==sum);
        if(dp[n][sum]!=-1) return dp[n][sum];
        bool take=false;
        if(arr[n]<=sum){
            take =f(n-1,arr,sum-arr[n],dp);}
        bool nottake=f(n-1,arr,sum,dp);
        return dp[n][sum]= take | nottake ;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum = sum / 2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,nums,sum,dp);
    }
};