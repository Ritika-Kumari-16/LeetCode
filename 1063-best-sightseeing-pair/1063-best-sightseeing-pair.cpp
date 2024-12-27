class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();
        vector<int>vec(n,0);
        int maxi=0;
        for( int i=0;i<n;i++){
            if(values[i]+i>maxi){
                maxi=values[i]+i;
            }
            vec[i]=maxi;
        }
        maxi=0;
        for(int j=1;j<n;j++){
            if(vec[j-1]+values[j]-j>maxi){
                maxi=vec[j-1]+values[j]-j;
            }
        }
        return maxi;
    }
};