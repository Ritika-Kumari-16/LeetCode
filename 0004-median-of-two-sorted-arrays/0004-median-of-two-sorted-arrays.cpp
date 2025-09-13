class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        if(n>m) return findMedianSortedArrays(nums2 , nums1);
        int k= (n+m+1)/2;
        int low=0;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int left1=INT_MIN , left2=INT_MIN;
            int right1=INT_MAX , right2=INT_MAX;
            if(mid>0) left1=nums1[mid-1];
            if(mid<n) right1=nums1[mid];
            int reqnos= k-mid;
            if(reqnos>0) left2=nums2[reqnos-1];
            if(reqnos<m) right2=nums2[reqnos]; 
            if(left1<=right2 && left2<=right1){
                if((n+m)%2==1) return (double)max(left1,left2);
                else{
                    double ans= (double)(max(left1,left2)+min(right1,right2))/2;
                    return ans;
                }
            }
            else if(left1>right2) high=mid-1;
            else low=mid+1;
        }
        return -1;
        
    }
};