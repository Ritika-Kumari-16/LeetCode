class Solution {
public:
long long getsum(vector<int>&nums , int divisor){
    long long sum=0;
    for(int i=0;i<nums.size();i++){
        sum+= ceil(nums[i]/(double)divisor);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid= low+(high-low)/2;
            long long sum=getsum(nums,mid);
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