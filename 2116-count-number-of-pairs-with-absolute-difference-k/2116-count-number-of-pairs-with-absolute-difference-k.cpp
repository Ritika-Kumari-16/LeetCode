class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int totalcount=0;
        for(int i=0;i<nums.size();i++){
            int reqno1=nums[i]-k;
            int reqno2=nums[i]+k;
            totalcount+=mpp[reqno1];
            totalcount+=mpp[reqno2];
            mpp[nums[i]]++;
        }
        return totalcount;
    }
};