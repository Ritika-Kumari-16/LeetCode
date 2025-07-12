class Solution {
public:
    void solve( int i , int  n, vector<int>&temp , vector<int>&nums , vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int idx=i;idx<n;idx++){
            if(idx>i && nums[idx]==nums[idx-1]) continue;
            temp.push_back(nums[idx]);
            solve(idx+1,n,temp,nums,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n,temp,nums,ans);
        return ans;
    }
};