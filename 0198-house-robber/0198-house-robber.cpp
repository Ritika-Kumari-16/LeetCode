class Solution {
public:
    int solve(vector<int>& nums , int n , vector<int>&dp){
        dp[0]=nums[0];
        for(int i=1;i<=n;i++){
        int take = nums[i];
        if(i>1) { take+=dp[i-2];}
        int nottake =dp[i-1];
        dp[i]=max(take , nottake);}
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,0);
        return solve(nums,n-1,dp);
    }
};

// class Solution {
// public: 
//     int solve(int n,vector<int>&nums,vector<int>&dp){
//        dp[0]=nums[0];
//        for(int i=1;i<n;i++){
//         int sel=nums[i];
//         if(i>1){
//             sel+=dp[i-2];
//         }
//         int notsel=dp[i-1];
       
//        dp[i]=max(sel,notsel);
//        }
//        return dp[n-1];
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//        vector<int>dp(n,0);
//         return solve(n,nums,dp);
//     }
// };