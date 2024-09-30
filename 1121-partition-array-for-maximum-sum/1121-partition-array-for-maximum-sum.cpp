class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        // Iterate through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--)
        {
            int ans = 0;
            int temp = 0;
            int len = 0;

            // Iterate within the current partition
            for (int i = ind; i < min(ind + k, n); i++)
            {
                len++;
                temp = max(temp, arr[i]);
                int element = temp * (i - ind + 1) + dp[i + 1];
                ans = max(ans, element);
            }

            // Update the dp array for the current index
            dp[ind] = ans;
        }

        return dp[0];
    }
};