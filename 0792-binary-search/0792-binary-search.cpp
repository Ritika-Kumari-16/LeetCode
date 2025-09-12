class Solution {
public:
int recsearch(vector<int>&nums, int low , int high , int target){
    if(low>high) return -1;
    int mid= low+(high-low)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]>target) return recsearch(nums,0,mid-1,target);
    else return recsearch(nums,mid+1,high,target);
}
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        return recsearch(nums,0,n-1 , target);
        
    }
};