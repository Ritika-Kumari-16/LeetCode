class Solution {
public:
int lowerBound(vector<int> &nums, int x){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==x){
                idx=mid;
                high=mid-1;
            }
            else if(nums[mid]>x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return idx;
    }
    int upperBound(vector<int> &nums, int x){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==x){
                idx=mid;
                low=mid+1;
            }
            else if(nums[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;;
            }

        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstocc= lowerBound(nums,target);
        int lastocc= upperBound(nums,target);
        return {firstocc,lastocc};
        
    }
};