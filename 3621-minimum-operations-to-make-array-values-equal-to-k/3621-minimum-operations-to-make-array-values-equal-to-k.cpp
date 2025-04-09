class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();
      sort(nums.begin(),nums.end());
      reverse(nums.begin(),nums.end());
      int count=0;
      if(k<=nums[nums.size()-1]){
        int i=1;
        while(i<nums.size()){
            if(nums[i]!=nums[i-1]){
                count++;
            }
            i++;
        }
      }else{
        return -1;
      }
      if(nums[n-1]!=k) count++;
      return count;
    }
};