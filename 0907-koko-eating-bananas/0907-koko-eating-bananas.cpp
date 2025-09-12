class Solution {
public:
long long gethrs(vector<int>&piles , int k){
    long long hrs=0;
    for(int i=0;i<piles.size();i++){
        hrs+=(long long) ceil((double)piles[i]/(double)k);
    }
    return hrs;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long timetaken=gethrs(piles,mid);
            if(timetaken<=h){
                ans=mid;
                high=mid-1;
            }
            else {low=mid+1;
            }
        }
        return ans;
    }
};