class Solution {
public:
void merge(vector<int>&nums , int low , int mid , int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
}
int pairscnt(vector<int>&nums , int low , int mid , int high){
    int count=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high ){
            long long val=(long long)2*nums[right];
            if(val<nums[i]){
            right++;
            }
            else{
                break;
            }
        }
        count+=(right-(mid+1));
    }
    return count;
}
int countpairs(vector<int>&nums , int i , int n){
    int count=0;
    if(i>=n) return count;
    int mid= i+(n-i)/2;
    count+=countpairs(nums,i,mid);
    count+=countpairs(nums,mid+1,n);
    count+=pairscnt(nums,i,mid,n);
    merge(nums,i,mid,n);
    return count;
}
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        return countpairs(nums,0,n-1);
    }
};