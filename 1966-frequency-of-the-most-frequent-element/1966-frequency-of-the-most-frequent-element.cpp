class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
        long long csum=0;
        int n= nums.size();
        int result=-1;
        while(r<n){
            csum+=nums[r];
            long long target= nums[r];
            long long reqsum= target*(r-l+1);
            long long op= reqsum-csum;
            if(op>k){
                csum-=nums[l];
                l++;
            }
            result=max(result,(r-l+1));
            r++;
        }
        return result;
    }
};