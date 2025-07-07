class Solution {
    typedef long long ll;
public:
    long long solve(vector<int>&bloomDay , int day , int k){
        ll possbouq=0;
        ll count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else{
                possbouq+=(count/k);
                count=0;
            }
        }
        possbouq+=(count/k);
        return possbouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long  n = bloomDay.size();

        if(1ll * m * 1ll* k > n) return -1;
        ll low= *min_element(bloomDay.begin(),bloomDay.end());
        ll high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            ll mid= low+(high-low)/2;
            ll possbouq= solve(bloomDay,mid,k);
            if(possbouq>=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};