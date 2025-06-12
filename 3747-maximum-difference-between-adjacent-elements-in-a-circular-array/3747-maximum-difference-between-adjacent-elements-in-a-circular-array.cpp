class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxdiff=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            int diff = abs(nums[i]-nums[i+1]);
            maxdiff=max(maxdiff,diff);
        }
        maxdiff=max(maxdiff,abs(nums[0]-nums[nums.size()-1]));
        return maxdiff;
    }
};