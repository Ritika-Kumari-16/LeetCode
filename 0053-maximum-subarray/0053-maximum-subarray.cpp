class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int psum=0;
        int maxsum=-1;
        int maxnsum=INT_MIN;
        int n = nums.size();
        int l=0;
        while(l<n){
            if(psum+nums[l]>=0){
                psum+=nums[l];
                maxsum=max(maxsum,psum);
            }
            else{
                psum=0;
                maxnsum=max(maxnsum,nums[l]);
            }
            l++;
            
        }
        if(maxsum !=-1 ) return maxsum;
        return maxnsum;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size()  ;
//         vector<int>prefixSum(n+1) , minprefixSum(n+1) ;
//         prefixSum[0] = 0 ;
//         minprefixSum[0] =  0 ;
//         int maxi = nums[0] ;
//         for (int i = 1 ; i < n+1 ; i++){
//             prefixSum[i] = prefixSum[i-1] + nums[i-1] ;
//             minprefixSum[i] = min(minprefixSum[i-1] , prefixSum[i]) ;
//             maxi = max(maxi , (prefixSum[i] - minprefixSum[i-1])) ;


//         }

//         return maxi ; 
//     }
// };