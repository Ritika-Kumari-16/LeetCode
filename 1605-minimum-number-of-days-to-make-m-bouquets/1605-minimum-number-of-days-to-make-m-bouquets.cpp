class Solution {
public:
long long findbouquets(vector<int>&nums , int k , int day){
    int count=0;
    long long total=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=day){
            count++;
        }
        else{
            total+=count/k;
            count=0;
        }
    }
    total+=count/k;
    return total;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if((long long)k*m > (long long)n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            long long totalbouquets = findbouquets(bloomDay,k,mid);
            if(totalbouquets>=m){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};