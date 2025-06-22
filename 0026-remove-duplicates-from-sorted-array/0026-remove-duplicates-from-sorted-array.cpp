class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =1;
        int n=  nums.size();
        while(i<n && nums[i-1] <nums[i]){
            i++;
        }
        int j =i+1;
        while(i<n && j<n){
            if(nums[i]!=nums[j] && nums[j]!=nums[i-1] && nums[j]>nums[i-1]){
                swap(nums[i],nums[j]);
                i++;
                j=i+1;

            }
            else{
                j++;
            }

        }
        return i;
    }
};