class Solution {
public:
int countsub(vector<int>&nums, int k){
    if(k<0) return 0;
        int l=0,r=0;
        int n= nums.size();
        int count=0;
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size()<=k){
                count+=r-l+1;
            }
            r++;
        }
        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return countsub(nums,k)-countsub(nums,k-1);
    }
};