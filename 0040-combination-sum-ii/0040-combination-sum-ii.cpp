class Solution {
private:
    void findcomb( int ind,int target,vector<int>&arr,vector<vector<int>>
    &ans,vector<int>&comb){
            if(target==0){
                ans.push_back(comb);
                return ;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            comb.push_back(arr[i]);
            findcomb(i+1,target-arr[i],arr,ans,comb);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>comb;
        findcomb(0,target,candidates,ans,comb);
        return ans;
        
    }
};