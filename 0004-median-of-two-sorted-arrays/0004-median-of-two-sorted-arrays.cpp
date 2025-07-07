class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m= nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);

        int noofele= (n+m+1)/2;
        int low=0;
        int high=n;
        while(low<=high){
            int mid= low+(high-low)/2;
            int remel=noofele-mid;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX , r2 = INT_MAX;
            if(mid-1>=0){
                l1=nums1[mid-1];
            }
            if(mid<n){
                r1=nums1[mid];
            }
            if(remel-1>=0){
                l2=nums2[remel-1];
            }
            if(remel<m){
                r2=nums2[remel];
            }
            if(l1<=r2 && l2<=r1){
                int left= max(l1,l2);
                int right=min(r1,r2);
                if((n+m)%2 ==0 ){
                    return (double)(left+right)/ (double )2;
                }
                else{
                    return left;
                }
            }
            else if(l1>r2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return 0;
    }
};