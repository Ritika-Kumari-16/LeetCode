class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int fstsmaller=INT_MAX;
        int secsmaller=INT_MAX;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<fstsmaller){
                fstsmaller=nums[i];
            }
            else if (nums[i]<secsmaller && nums[i]>fstsmaller){
                secsmaller=nums[i];
            }
            else if(nums[i]>fstsmaller && nums[i]>secsmaller){
                return true;
            }
        }
        return false;
    }
};