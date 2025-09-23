class Solution {
public:
void generatecomb(int i , int n , vector<int>&candidates , int sum , int target ,vector<int>&temp , vector<vector<int>>&ans){
    if(sum==target){
        ans.push_back(temp);
        return ;
    }
    for(int j=i;j<n;j++){
        if(j>i && candidates[j]==candidates[j-1]) continue;
        if(candidates[j]+sum<=target){
            temp.push_back(candidates[j]);
            generatecomb(j+1,n,candidates,sum+candidates[j],target,temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n= candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        generatecomb(0,n,candidates,0,target,temp,ans);
        return ans;
    }
};