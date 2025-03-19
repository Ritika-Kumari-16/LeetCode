class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if (goal < 0) return 0;  // Edge case: negative goal
        
        int l = 0, r = 0, sum = 0, cnt = 0, n = nums.size();
        
        while (r < n) {
            sum += (nums[r]%2);
            
            while (sum > goal) {
                sum -= (nums[l]%2);
                l++;
            }
            
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
        
    }
};