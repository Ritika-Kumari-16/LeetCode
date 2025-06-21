class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n = nums.size();
        int mini=nums[0];
        int cntsub=0;
        while(i<n){
            while(i<n && nums[i]-mini<=k){
                i++;
            }
            if(i<n) {
                mini=nums[i];}
            cntsub++;
        }

        return cntsub;
    }
};