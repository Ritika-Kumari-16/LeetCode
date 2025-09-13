class Solution {
public:
int countsubarr(vector<int>&nums, int sum){
    int count=1;
    int totalsum=0;
    for(int i=0;i<nums.size();i++){
        if(totalsum+nums[i]<=sum){
            totalsum+=nums[i];
        }
        else{
            totalsum=nums[i];
            count++;
        }
    }
    return count;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0LL);
        int result=-1;
        if(k>n) return result;
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalsubarr= countsubarr(nums,mid);
            if(totalsubarr<=k){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
        
    }
};