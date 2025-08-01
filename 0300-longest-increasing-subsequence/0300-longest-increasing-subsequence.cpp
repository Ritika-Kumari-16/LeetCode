class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int previdx=0;previdx<i;previdx++){
                if(nums[previdx]<nums[i]){
                    dp[i]=max(dp[i],1+dp[previdx]);
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};

// class Solution {
// public:
// int solve(int i , int previdx , int n , vector<int>&nums ,vector<vector<int>>&dp ){
//     if(i==n+1)  return 0;
//     if(dp[i][previdx]!=-1) return dp[i][previdx];
//     //take it 
//     int take =0;
//     if(previdx==0 || nums[previdx-1]<nums[i-1]){
//         take= 1+solve(i+1,i,n,nums,dp);
//     }
//     int nottake= solve(i+1,previdx,n,nums,dp);
//     return dp[i][previdx]= max(take, nottake);
// }
//     int lengthOfLIS(vector<int>& nums) {
//         int n= nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(1,0,n,nums,dp);
        
//     }
// };