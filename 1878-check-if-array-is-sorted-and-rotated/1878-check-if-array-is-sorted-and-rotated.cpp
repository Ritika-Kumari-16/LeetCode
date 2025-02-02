class Solution {
public:
    bool check(vector<int>& nums) {
        int brkpts=0;
        int n= nums.size();
        int j=0;
        int k=n-1;
        while(j<k){
            if (nums[j]!=nums[k]){
                break;

            }
            j++;
            k--;
        }
        if(j==k || j>k) return true;
        for( int i=j+1;i<=k;i++){
            if(nums[i-1]>nums[i]){
                brkpts++;
            }
        }
        if(nums[j]<nums[k] && brkpts ==0 || nums[j]> nums[k] && brkpts==1) return true;
        return false;

        
    }
};