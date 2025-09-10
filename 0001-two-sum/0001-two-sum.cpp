class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int reqno=target-nums[i];
            if(mpp.find(reqno)!=mpp.end()){
                return {i,mpp[reqno]};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};