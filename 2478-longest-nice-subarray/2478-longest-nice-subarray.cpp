class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int temp=0;
        int l=0;
        int r=0;
        int maxlen=1;
        int n= nums.size();
        while(r<n){
            while((temp & nums[r] )!= 0){
                temp=(temp^nums[l]);
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            temp=(temp| nums[r]);
            r++;
        }
        return maxlen;
        
    }
};