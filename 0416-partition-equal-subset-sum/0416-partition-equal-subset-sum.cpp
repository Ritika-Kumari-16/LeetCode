class Solution {
public:
    bool solve(int i , int n , vector<int>&nums, int target , vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==n-1) return nums[n-1]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        //nottake 
        bool nottake= solve(i+1,n,nums,target,dp);
        //take
        bool take= false;
        if(nums[i]<=target){
            take= solve(i+1,n,nums,target-nums[i],dp);
        }
        return dp[i][target]=nottake || take ; 
    }
    bool canPartition(vector<int>& nums) {
        int sum= accumulate(nums.begin(), nums.end(),0);
        if(sum%2==1) return false;
        vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));
        return solve(0,nums.size(),nums,sum/2,dp);
        
    }
};