class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n= nums.size();
        int p=0,q=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) return false;
            if(nums[i-1]>nums[i]){
                p=i-1;
                if(p==0) return false;
                break;
            }
        }
        for(int i=p+1;i<n;i++){
            if(nums[i-1]==nums[i]) return false;
            if(nums[i-1]<nums[i]){
                q=i-1;
                if(q==n-1) return false;
                break;
            }
        }
        for(int i=q+1;i<n;i++){
            if(nums[i-1]==nums[i]) return false;
            if(nums[i-1]>nums[i]){
                return false;
            }
        }
        if(q==0 || q==n-1) return false;
        return true;
    }
};