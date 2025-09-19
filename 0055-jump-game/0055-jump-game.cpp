class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int maxidx=nums[0];
        for(int i=0;i<n;i++){
            if(maxidx<i) return false;
            maxidx=max(maxidx,i+nums[i]);
        }
        return true;
    }
};