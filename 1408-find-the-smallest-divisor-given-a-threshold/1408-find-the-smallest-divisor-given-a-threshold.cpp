class Solution {
    typedef long long ll;
public:
ll solve(vector<int>&nums , int val){
    ll totalthrhold=0;
    for(int i=0;i<nums.size();i++){
        totalthrhold+=ceil(double(nums[i])/double(val));
    }
    return totalthrhold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        ll low=1;
        ll high= *max_element(nums.begin(),nums.end());
        while(low<=high){
            ll mid= low+(high-low)/2;
            ll thrhold= solve(nums,mid);
            if(thrhold <=threshold){
                high=mid-1;
            } 
            else{
                low=mid+1;
            }
        }
        return low;
    }
};