class Solution {
public:
void generateSubsets(int i , int n , vector<int>&temp , vector<vector<int>>&ans,vector<int>nums){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    //take it 
    temp.push_back(nums[i]);
    generateSubsets(i+1,n,temp,ans,nums);
    temp.pop_back(); 

    //not take it
    generateSubsets(i+1,n,temp,ans,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        generateSubsets(0,n,temp,ans,nums);
        return ans;
        
    }
};