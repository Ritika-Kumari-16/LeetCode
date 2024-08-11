class Solution {
private:
    void findsubset( int ind,vector<int>&arr,vector<vector<int>>
    &ans,vector<int>&subset){
            ans.push_back(subset);
            for(int i=ind;i<arr.size();i++){
                if(i>ind && arr[i]==arr[i-1]) continue;
                subset.push_back(arr[i]);
                findsubset(i+1,arr,ans,subset);
                subset.pop_back();
            }
        }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        findsubset(0,nums,ans,subset);
        return ans;
        
    }
};