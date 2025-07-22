class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m=nums2.size();
        int l=0,r=0;
        int minno=-1;
        while(l<n && r<m){
            if(nums1[l]==nums2[r]){
                minno=nums1[l];
                break;
            }
            else if( nums1[l]<nums2[r]){
                l++;
            }
            else{
                r++;
            }
        }
        return minno;
    }
};