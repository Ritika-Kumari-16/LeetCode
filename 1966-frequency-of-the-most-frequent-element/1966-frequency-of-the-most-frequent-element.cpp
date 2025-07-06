class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r =0;
        int n= nums.size();
        long long csum=0;
        int result=-1;
        while(r<n){
            long long target= nums[r];
            csum+=nums[r];
            long long reqsum = target * (r-l+1);
            long long ops= reqsum-csum;
            if(ops>k){
                csum-=nums[l];
                l++;
            }
            result= max(result,(r-l+1));
            r++;
        }
        return result;
    }
};