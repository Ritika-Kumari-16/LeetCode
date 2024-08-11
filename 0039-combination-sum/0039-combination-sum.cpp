class Solution {
private:
    void findcomb( int ind,int target,vector<int>&arr,vector<vector<int>>
    &ans,vector<int>&comb){
        if(ind>arr.size()-1){
            if(target==0){
                ans.push_back(comb);
            }
            return ;
        }
        if(arr[ind]<=target){
            comb.push_back(arr[ind]);
            findcomb(ind,target-arr[ind],arr,ans,comb);
            comb.pop_back();
        }
        findcomb(ind+1,target,arr,ans,comb);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>comb;
        findcomb(0,target,candidates,ans,comb);
        return ans;
        
    }
};