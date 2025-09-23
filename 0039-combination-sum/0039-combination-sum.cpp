class Solution {
public:
void generatecomb(int i, int n , vector<int>&candidates , int sum , int target , vector<int>&temp ,vector<vector<int>>&ans){
    if(i==n){
        if(sum==target){
            ans.push_back(temp);
        }
        return ;
    }
    //take 
    if(candidates[i]+sum <=target){
        temp.push_back(candidates[i]);
        generatecomb(i , n , candidates , sum+candidates[i] , target ,temp , ans);
        temp.pop_back();
    }
    generatecomb(i+1,n,candidates,sum,target,temp,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n= candidates.size();
        generatecomb(0,n,candidates,0,target,temp,ans);
        return ans;
    }
};