class Solution {
public:
void generatesubsets(int i , int n , vector<int>&nums , vector<int>&temp , vector<vector<int>>&ans){
    if(i==n) {
        ans.push_back(temp);
        return ;
    }
    //takeit 
    temp.push_back(nums[i]);
    generatesubsets(i+1,n,nums,temp,ans);
    
    //do not take it
    temp.pop_back();
    generatesubsets(i+1,n,nums,temp,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        generatesubsets(0,n,nums,temp,ans);
        return ans;
    }
};