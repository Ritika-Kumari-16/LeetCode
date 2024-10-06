class Solution {
public:

int findIntegers(int n) {
    int dp[31] = {0};
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= 30; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int ans = 0, pre = 0;
    for (int i = 29; i >= 0; i--) {
        if ((n & (1 << i)) != 0) {
            ans += dp[i];
            if (pre == 1) {
                ans--;
                break;
            }
            pre = 1;
        } else {
            pre = 0;
        }
    }
    return ans + 1;
}
        
};