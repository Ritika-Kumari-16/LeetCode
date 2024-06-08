class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[2*j]=nums[i];
                j++;
            }
            else{
                ans[2*k+1]=nums[i];
                k++;
            }
        }
        return ans;
        
    }
};