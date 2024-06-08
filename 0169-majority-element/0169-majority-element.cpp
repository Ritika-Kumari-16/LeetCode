class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int i=0;
        for(int j=i;j<nums.size();j++){
            if(nums[j]==nums[i]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                i=j+1;
            }
        }
        if(count!=0){
            return nums[i];
        }
        else{
            return -1;
        }
    }
};