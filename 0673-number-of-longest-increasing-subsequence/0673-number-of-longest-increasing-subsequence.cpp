class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int previdx=0;previdx<i;previdx++){
                if(nums[previdx]<nums[i] && dp[i]<1+dp[previdx] ){
                    dp[i]=1+dp[previdx];
                    count[i]=count[previdx];
                }
                else if(nums[previdx]<nums[i] && dp[i]==1+dp[previdx] ){
                    count[i]+=count[previdx];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                cnt+=count[i];
            }
        }
        return cnt;
    }
};