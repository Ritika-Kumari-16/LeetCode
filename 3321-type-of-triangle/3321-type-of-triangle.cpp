class Solution {
public:
    bool scalenetri(vector<int>&nums){
        if(nums[0]+nums[1]<=nums[2]) return false;
        if(nums[1]+nums[2]<=nums[0]) return false;
        if(nums[0]+nums[2]<=nums[1]) return false;
        return true;
    }
    string triangleType(vector<int>& nums) {
        string ans;
        int same=1;
        sort(nums.begin(),nums.end());
        if(scalenetri(nums)==false){
            return "none";
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                same++;
            }
            
        }
        if(same==2){
            ans="isosceles";
        }
        else if(same==3){
            ans="equilateral";
        }
        else{
            if(scalenetri(nums)){
                ans="scalene";
            }
            else{
                ans="none";
            }
        }
        return ans;
    }
};