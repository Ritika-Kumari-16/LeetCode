class Solution {
  private:
    void findsubsets(int ind,vector<vector<int>>&ans,vector<int>&sbst,vector<int>&arr,int n){
        if(ind==n) {
            ans.push_back(sbst);
            return;
        }
        //taking ele
        sbst.push_back(arr[ind]);
        findsubsets(ind+1,ans,sbst,arr,n);
        //not taking ele
        sbst.pop_back();
        findsubsets(ind+1,ans,sbst,arr,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subsets;
        int n=nums.size();
        findsubsets(0,ans,subsets,nums,n);
        return ans;
        
    }
};