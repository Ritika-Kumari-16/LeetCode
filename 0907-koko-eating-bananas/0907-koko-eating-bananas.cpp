class Solution {
public:
long long solve(vector<int>&piles , int bananas){
    long long totalhrs=0;
    for(int i=0;i<piles.size();i++){
        totalhrs+=ceil(double(piles[i])/ double(bananas));
    }
    return totalhrs;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        if(h<n) return -1;
        int low=1;
        int high= *max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid= low+(high-low)/2;
            long long timetaken =solve(piles,mid);
            if(timetaken<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }
};