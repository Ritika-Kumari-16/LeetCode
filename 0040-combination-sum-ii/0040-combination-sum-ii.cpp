class Solution {
public:
void solve (int i, int n , int target , vector<vector<int>>&ans , vector<int>&nums , vector<int>&temp){
    if(target==0) {
        ans.push_back(temp);
        return;}
        
    for(int idx=i;idx<n;++idx){
        if(idx>i && nums[idx]==nums[idx-1]) continue;
        if(nums[idx]>target) break;
        temp.push_back(nums[idx]);
        solve(idx+1,n,target-nums[idx],ans,nums,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n,target,ans,candidates,temp);
        return ans;
    }
};