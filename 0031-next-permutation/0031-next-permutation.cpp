class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int brkpt=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                brkpt=i;
                break;
            }
        } 
        if(brkpt==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>brkpt;i--){
            if(nums[i]>nums[brkpt]){
                swap(nums[brkpt],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+brkpt+1 , nums.end());
        return ;
        
    }
};