class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) { 
        int maxlen=1;
        int num=0;
        int n= nums.size();
        int l=0,r=0;
        while(r<n){
            while(num & nums[r] !=0){
                num^=nums[l];
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            num|=nums[r];
            r++;
        }
        return maxlen;
    }
};