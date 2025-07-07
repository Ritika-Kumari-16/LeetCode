class Solution {
    typedef long long ll;
    ll solve(vector<int>&weights , int wgh){
        ll totaldays=1;
        ll weight=0;
        for(int i=0;i<weights.size();i++){
            if(weight+weights[i]<=wgh){
                weight+=weights[i];
            }
            else{
                weight=weights[i];
                totaldays++;
            }
        }
        return totaldays;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        ll low= *max_element(weights.begin(),weights.end());
        ll high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            ll mid= low+(high-low)/2;
            ll totaldays= solve(weights,mid);
            if(totaldays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};