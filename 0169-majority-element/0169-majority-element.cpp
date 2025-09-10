class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int el=nums[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el){
                count++;
            }
            else{
                count--;
            }
            if(count==0) {
                el=nums[i];
                count++;
            }
        }
        return el;
    }
};