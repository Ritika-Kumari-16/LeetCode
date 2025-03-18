class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int maxlen=1;
        int mask=0;
        int n= nums.size();
        while(r<n){
            while((mask & nums[r])!=0){
                mask=(mask^ nums[l]);
                l++;
            }
            maxlen=max(maxlen ,r-l+1);
            mask=(mask | nums[r]);
            r++;
        }
        return maxlen;
        
    }
};