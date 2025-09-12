class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        int minel=INT_MAX;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[low]<=nums[mid]){
                minel=min(minel,nums[low]);
                low=mid+1;
            }
            else{
                minel=min(minel,nums[mid]);
                high=mid-1;
            }
        }
        return minel;
    }
};