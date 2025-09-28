class Solution {
public:
int countways(int i , int sum , vector<int>&nums, int target ,int sum1, vector<vector<int>>&dp){
    if(i==nums.size()){
        if(sum+sum1==target+sum1) return 1 ;
        return 0;
    }
    if(dp[i][sum+sum1]!=-1) return dp[i][sum+sum1];
    int addways= countways(i+1,sum+nums[i],nums,target,sum1,dp);
    int subways= countways(i+1,sum-nums[i],nums,target,sum1,dp);
    return dp[i][sum+sum1]=addways+subways;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        // if(sum-target <0 || (sum-target)%2){
        //     return 0;
        // }
        // int s2= (sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return countways(0,0,nums,target,sum,dp);
    }
};