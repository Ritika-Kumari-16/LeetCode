class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int max_count=1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                count=1;
                max_count=1;
            }
            else if(nums[i]==maxi){
                count++;
                max_count=max(max_count,count);
            }
            else{
                count=0;
            }

        }
        return max_count;
    }
};