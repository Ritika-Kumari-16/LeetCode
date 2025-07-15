class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        int lastidx = 0;
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int previdx = 0; previdx < i; previdx++) {
                if ((nums[i]%nums[previdx] ==0) && dp[i] < 1 + dp[previdx]) {
                    dp[i] = 1 + dp[previdx];
                    hash[i] = previdx;
                }
            }
            if (maxi < dp[i]) {
                lastidx = i;
                maxi = dp[i];
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastidx]);
        while (lastidx != hash[lastidx]) {
            lastidx = hash[lastidx];
            ans.push_back(nums[lastidx]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};