class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mpp;
        int maxsum=0,sum=0;
        int l=0,r=0;
        while(r<n){
            while(mpp.find(nums[r])!=mpp.end()){
                sum-=nums[l];
                mpp.erase(nums[l]);
                l++;
            }
            sum+=nums[r];
            mpp[nums[r]]=1;
            maxsum=max(maxsum,sum);
            r++;
        }
        return maxsum;
    }
};