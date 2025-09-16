class Solution {
public:
int noofsub(vector<int>&nums , int goal){
    int count=0;
    if(goal<0) return count;
    int l=0;
    int r=0;
    int n= nums.size();
    int sum=0;
    while(r<n){
        sum+=nums[r]%2;
        while(sum>goal){
            sum-=nums[l]%2;
            l++;
        }
        if(sum<=goal){
            count+=(r-l+1);
        }
        r++;
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return noofsub(nums,k)-noofsub(nums,k-1);
    }
};