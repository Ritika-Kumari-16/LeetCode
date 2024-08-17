class Solution {
public:
    int solve(vector<int>& nums , int n , vector<int>&dp){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int take = solve(nums,n-2,dp) + nums[n];
        int nottake =solve(nums,n-1,dp);
        return dp[n]=max(take , nottake);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n-1,dp);
    }
};