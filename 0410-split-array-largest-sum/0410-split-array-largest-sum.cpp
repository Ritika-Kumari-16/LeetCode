int maxsubarr(vector<int>&arr,int mid){
    int splits=1;
    int summ=0;
    for(int i=0;i<arr.size();i++){
        if(summ+arr[i]<=mid){
            summ+=arr[i];
        }
        else{
            splits++;
            summ=arr[i];

        }
    }
    return splits;
}
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxarr=maxsubarr(nums,mid);
            if(maxarr>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return low;
    }
};