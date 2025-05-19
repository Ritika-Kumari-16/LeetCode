class Solution {
public:
    int nodays(vector<int>&weights , int weight){
        int reqdays=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=weight){
                load+=weights[i];
            }
            else{
                reqdays++;
                load=weights[i];
            }
        }
        return reqdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini= *max_element(weights.begin(),weights.end());
        int maxi = accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(mini<=maxi){
            int mid= mini+(maxi-mini)/2;
            int reqdays=nodays(weights,mid);
            if(reqdays>days){
                mini=mid+1;
            }
            else{
                ans= mid;
                maxi=mid-1;
            }
        }
        return ans;
        
    }
};