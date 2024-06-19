int tdays(vector<int>arr,int capacity){
    long long load=0;
    int day=1;
    for(int i=0;i<arr.size();i++){
        if(load+arr[i]<=capacity){
            load+=arr[i];
        }
        else{
            day++;
            load=arr[i];
        }
    }
    return day;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long low= *max_element(weights.begin(),weights.end());
        long long high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long totaldays=tdays(weights,mid);
            if(totaldays>days){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};