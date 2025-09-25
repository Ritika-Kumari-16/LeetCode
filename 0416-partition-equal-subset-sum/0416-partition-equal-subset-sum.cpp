class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        sum=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[n-1]<=sum){
            dp[n-1][nums[n-1]]=true;
        }
        for(int i=n-2;i>=0;i--){
            for(int target=1;target<=sum;target++){
                bool take=false;
                if(nums[i]<=target){
                    take=dp[i+1][target-nums[i]];
                }
                bool nottake=dp[i+1][target];
                dp[i][target]= take || nottake;
            }
        }
        return dp[0][sum];
    }
};