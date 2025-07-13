class Solution {
public:
int solve(int i , int n , vector<int>&nums, vector<int>&dp){
    if(i==n-1) return nums[i];
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    //take 
    int take = nums[i]+solve(i+2,n,nums,dp);
    int nottake= solve(i+1,n,nums,dp);
    return dp[i]=max(take , nottake);
}
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return solve(0,n,nums,dp);
        
    }
};