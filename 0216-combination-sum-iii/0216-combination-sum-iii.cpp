class Solution {
public:
void generatecomb(int i , int target , int k , vector<int>&temp , vector<vector<int>>&ans){
    if(temp.size()>k) return;
    if(target==0 && temp.size()==k){
        ans.push_back(temp);
        return ;
    }
    for(int j=i;j<=9;j++){
        if(j>target) break;
        temp.push_back(j);
        generatecomb(j+1,target-j,k,temp,ans);
        temp.pop_back();
    }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        generatecomb(1,n,k,temp,ans);
        return ans;
    }
};