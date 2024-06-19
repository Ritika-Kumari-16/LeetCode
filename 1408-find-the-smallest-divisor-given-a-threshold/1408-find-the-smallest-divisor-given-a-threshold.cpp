class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        long long high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            long long mid= low+(high-low)/2;
            long long sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=ceil((double)nums[i]/(double)mid);
            }
            if(sum<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};