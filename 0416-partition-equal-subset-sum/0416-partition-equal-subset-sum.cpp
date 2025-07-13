class Solution {
public:
bool solve(int i , int n , int target , vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(i==n) return false;
    //take 
    if(dp[i][target]!=-1 ) return dp[i][target];
    bool take= false;
    if(arr[i]<=target){
        take =solve(i+1,n,target-arr[i],arr,dp);
    }
    bool nottake= solve(i+1,n,target,arr,dp);
    return dp[i][target]= take || nottake;
}
    bool canPartition(vector<int>& nums) {
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target= sum/2;
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,n,target,nums,dp);
    }
};