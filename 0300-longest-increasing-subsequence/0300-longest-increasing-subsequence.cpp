#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,int last,vector<int>&nums , int n , vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][last+1]!=-1) return dp[ind][last+1];
        int nottake= 0 + solve(ind+1,last,nums,n,dp);
        int take=-1;
        if(last==-1 || nums[ind]>nums[last]){
            take=1 + solve(ind+1,ind,nums,n,dp);
        }
        return dp[ind][last + 1] = max(take , nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,n,dp);
        
    }
};