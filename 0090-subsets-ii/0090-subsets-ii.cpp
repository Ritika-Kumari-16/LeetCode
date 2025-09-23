class Solution {
public:
void generatesubsets(int i, vector<int>&nums, vector<int>&temp , vector<vector<int>>&ans){
    ans.push_back(temp);
    for(int j=i;j<nums.size();j++){
        if(j>i && nums[j]==nums[j-1]) continue;
        temp.push_back(nums[j]);
        generatesubsets(j+1,nums,temp,ans);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        generatesubsets(0,nums,temp,ans);
        return ans;
    }
};