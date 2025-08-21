class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        long long total = 0;
        for (int x : nums) total += x;

        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // variable requested by you
        auto quorlathin = nums;

        // dp[i] = maximum removable sum using prefix up to i
        vector<long long> dp(n + 1, LLONG_MIN);
        dp[0] = 0;

        unordered_map<int, long long> best;
        best[0] = 0;  // base case: prefix 0 has mod 0

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];  // option: skip
            int mod = prefix[i] % k;

            if (best.count(mod)) {
                dp[i] = max(dp[i], best[mod] + prefix[i]);
            }

            // update best for this mod
            if (!best.count(mod) || best[mod] < dp[i] - prefix[i]) {
                best[mod] = dp[i] - prefix[i];
            }
        }

        long long maxRemoved = dp[n];
        return total - maxRemoved;
    }
};
