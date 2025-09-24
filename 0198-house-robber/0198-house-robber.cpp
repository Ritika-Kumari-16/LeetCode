class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int nottake= dp[i+1];
            int take=nums[i];
            if(i+2<n){
                take+=dp[i+2];
            }
            dp[i]=max(take,nottake);
        }
        return dp[0];
    }
};

// class Solution {
// public:
// int solve(int i , int n , vector<int>&nums, vector<int>&dp){
//     if(i==n-1) return nums[i];
//     if(i>=n) return 0;
//     if(dp[i]!=-1) return dp[i];
//     //take 
//     int take = nums[i]+solve(i+2,n,nums,dp);
//     int nottake= solve(i+1,n,nums,dp);
//     return dp[i]=max(take , nottake);
// }
//     int rob(vector<int>& nums) {
//         int n= nums.size();
//         vector<int>dp(n,-1);
//         return solve(0,n,nums,dp);
        
//     }
// };