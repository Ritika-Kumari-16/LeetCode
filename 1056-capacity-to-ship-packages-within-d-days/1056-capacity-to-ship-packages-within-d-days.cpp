class Solution {
public:
int getdays(vector<int>&weights , int weight){
    int totaldays=1;
    int wt=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+wt<=weight){
            wt+=weights[i];
        }
        else{
            totaldays++;
            wt=weights[i];
        }
    }
    return totaldays;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int totaldays=getdays(weights, mid);
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