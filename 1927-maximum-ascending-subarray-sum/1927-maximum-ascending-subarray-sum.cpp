class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=0;
        int n = nums.size();
        for( int i=0;i<n;i++){
            int sum=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j-1]<nums[j]){
                    sum+=nums[j];
                    maxsum=max(maxsum,sum);
                }
                else{
                    break;
                }
            }
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};