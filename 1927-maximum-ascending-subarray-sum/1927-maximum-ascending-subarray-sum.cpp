class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=nums[0];
        int n = nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                sum+=nums[i];
                maxsum=max(maxsum,sum);
            }
            else{
                sum=nums[i];
            }
        }

        // for( int i=0;i<n;i++){
        //     int sum=nums[i];
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j-1]<nums[j]){
        //             sum+=nums[j];
        //             // maxsum=max(maxsum,sum);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     maxsum=max(maxsum,sum);
        // }
        return maxsum;
    }
};