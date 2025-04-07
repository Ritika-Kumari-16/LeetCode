class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        if (arr[0] <= target)
            dp[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = target; t >= 0; t--) {
                if (arr[i] <= t)
                    dp[t] = dp[t] || dp[t - arr[i]];
            }
        }

        return dp[target];
    }
};
