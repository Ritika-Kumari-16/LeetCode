class Solution {
public:
    int rob(vector<int>& nums) {
        int m= nums.size();
        if(m==1) return nums[0];
        vector<int>nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        vector<int>dp1(m-1,0);
        vector<int>dp2(m-1,0);
        dp1[m-2]=nums1[m-2];
        dp2[m-2]=nums2[m-2];
        for(int i=m-3;i>=0;i--){
            int nottake= dp1[i+1];
            int take=nums1[i];
            if(i+2<m-1){
                take+=dp1[i+2];
            }
            dp1[i]=max(take,nottake);
        }
        for(int i=m-3;i>=0;i--){
            int nottake= dp2[i+1];
            int take=nums2[i];
            if(i+2<m-1){
                take+=dp2[i+2];
            }
            dp2[i]=max(take,nottake);
        }
        return max(dp1[0],dp2[0]);
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
//         if(n==1) return nums[0];
//         vector<int>dp1(n-1,-1);
//         vector<int>dp2(n-1,-1);
//         vector<int>nums1(nums.begin(),nums.end()-1);
//         vector<int>nums2(nums.begin()+1, nums.end());
//         return max(solve(0,n-1,nums1,dp1),solve(0,n-1,nums2,dp2));
        
//     }
// };