class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxidx=0;
        int jump=0;
        for(int i=0;i<n;i++){
            if(maxidx<i) return false;
            jump=nums[i]+i;
            maxidx=max(maxidx,jump);
        }
        return true;
    }
};