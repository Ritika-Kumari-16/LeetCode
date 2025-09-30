class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<int>dp(n,1);
        vector<int>parent(n,0);
        int idx=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=0;j<i;j++){
                if((nums[i] % nums[j]==0)&& dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    parent[i]=j;
                }
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
                idx=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[idx]);
        while(parent[idx]!=idx){
            idx=parent[idx];
            ans.push_back(nums[idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};