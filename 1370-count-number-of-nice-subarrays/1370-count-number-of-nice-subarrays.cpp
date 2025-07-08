class Solution {
public:
    int countarr(vector<int>&nums , int k){
        if(k<0) return 0;
        int l=0,r=0,count=0;
        int n = nums.size();
        int oddcnt=0;
        while(r<n){
            if(nums[r]%2==1){
                oddcnt++;
            }
            while(oddcnt>k){
                if(nums[l]%2==1){
                    oddcnt--;
                }
                l++;
            }
            if(oddcnt<=k){
                count+=r-l+1;
            }
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countarr(nums,k)-countarr(nums,k-1);
        
    }
};