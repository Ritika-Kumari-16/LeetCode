class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();
        int result=0;
        if(n%2==0 && m%2==0) return result;
        //for num 1 we are checking 
        if(m%2==1){
            for(int i=0;i<n;i++){
                result ^=nums1[i];
            }
        }
        // for num2 we are checking
        if(n%2==1){
            for(int j=0;j<m;j++){
                result^=nums2[j];
            }
        }
        return result;
        
    }
};