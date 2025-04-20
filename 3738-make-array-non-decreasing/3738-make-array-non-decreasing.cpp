class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int>ans;
        int n= nums.size();
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]<ans.back()){
                continue;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans.size();
    }
};