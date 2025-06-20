class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n= nums.size();
        long long maxpro=LLONG_MIN;
        if(m==1){
            for(int i=0;i<n;i++){
                long long val= (long long )nums[i]*nums[i];
                maxpro=max(maxpro,val);
            }
            return maxpro;
        }
        vector<int>prefixmax(n,LLONG_MIN);
        vector<int>prefixmin(n,LLONG_MAX);
        prefixmax[0]=nums[0];
        prefixmin[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixmax[i]=max(prefixmax[i-1],nums[i]);
            prefixmin[i]=min(prefixmin[i-1],nums[i]);
        }
        for(int i=m-1;i<n;i++){
            long long op1= (long long )nums[i]*prefixmax[i-(m-1)];
            long long op2=(long long ) nums[i]*prefixmin[i-(m-1)];
            
            maxpro=max(maxpro,max(op1,op2));
        }
        return maxpro;
    }
};