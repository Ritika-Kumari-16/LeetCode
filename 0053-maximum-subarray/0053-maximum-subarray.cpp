class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int psum=0;
        int maxsum=-1;
        int nsum=0;
        int maxnsum=INT_MIN;
        int n = nums.size();
        int l=0;
        while(l<n){
            if(psum+nums[l]>=0){
                nsum=0;
                psum+=nums[l];
                maxsum=max(maxsum,psum);
            }
            else{
                psum=0;
                nsum=nums[l];
                maxnsum=max(maxnsum,nsum);
            }
            l++;
            
        }
        if(maxsum !=-1 ) return maxsum;
        return maxnsum;
    }
};