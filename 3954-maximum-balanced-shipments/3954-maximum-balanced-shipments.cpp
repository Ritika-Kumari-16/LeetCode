class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n= weight.size();
        int maxval=-1;
        int maxshipments=0;
        for(int i=0;i<n;i++){
            maxval=max(maxval,weight[i]);
            if(weight[i]<maxval){
                maxshipments++;
                maxval=-1;
            }
        }
        return maxshipments;
    }
};