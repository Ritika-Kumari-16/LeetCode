class Solution {
public:
void solve(int i, int n , int sum , int target , vector<int>&temp , vector<vector<int>>&ans , vector<int>nums){
    if(i==n){
        if(sum==target) ans.push_back(temp);
        return;
    }
    //take 
    
    if(sum+nums[i]<=target){
        temp.push_back(nums[i]);
        solve(i,n,sum+nums[i],target,temp,ans,nums);
        temp.pop_back();
    }
    solve(i+1,n,sum,target,temp,ans,nums);
    

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates.size(),0,target,temp,ans,candidates);
        return ans;
    }
};