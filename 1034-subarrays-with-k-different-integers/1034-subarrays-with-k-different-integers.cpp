class Solution {
public:
int countsubarray(vector<int>&nums , int k){
    unordered_map<int,int>mpp;
    int n= nums.size();
    if(k<0) return 0;
    int count=0;
    int l=0,r=0;
    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
        }
        count+=(r-l+1);
        r++;
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countsubarray(nums,k)-countsubarray(nums,k-1);
        
    }
};