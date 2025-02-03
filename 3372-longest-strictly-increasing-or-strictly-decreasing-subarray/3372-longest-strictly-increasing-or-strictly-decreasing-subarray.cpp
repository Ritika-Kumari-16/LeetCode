class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n= nums.size();
        int maxlen=1;
        int inclen=1;
        int declen=1;
        for( int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                inclen++;
                declen=1;
            }
            else if(nums[i-1]>nums[i]){
                declen++;
                inclen=1;
            }
            else{
                inclen=1;
                declen=1;
            }
            maxlen=max(maxlen,max(inclen,declen));
        }
        return maxlen;
        
    }
};