class Solution {
public:
int maxenergy(int i , vector<int>&energy , int k){
    int n= energy.size();
    if(i>=n) return 0;
    //take energyy
    int take=energy[i]+maxenergy(i+k,energy,k);
    //nottake
    int nottake=maxenergy(i+1,energy,k);
    return max(take,nottake);
}
    int maximumEnergy(vector<int>& energy, int k) {
        int n= energy.size();
        vector<int>dp(n,0);
        int maxenergyans=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int en= energy[i];
            if(i+k<n) en+=dp[i+k];
            dp[i]=en;
            maxenergyans=max(maxenergyans,en);
        }
        return maxenergyans;
    }
};