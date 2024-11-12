class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;
        for(int i=0;i<nums.size();i++){
            int ind = i+nums[i];
            if(maxind<i) return false;
            if(maxind>=nums.size()-1){
                return true;
            }
            maxind=max(maxind,ind);
        }
        return true;
        }
};