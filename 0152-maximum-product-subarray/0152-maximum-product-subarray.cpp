class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxpro=INT_MIN;
        int prefixprod=1;
        int suffixprod=1;
        for(int i=0;i<n;i++){
            prefixprod*=nums[i];
            suffixprod*=nums[n-i-1];
            maxpro=max(maxpro,max(prefixprod,suffixprod));
            if(prefixprod==0) prefixprod=1;
            if(suffixprod==0) suffixprod=1;
        }
        return maxpro;   
    }
};