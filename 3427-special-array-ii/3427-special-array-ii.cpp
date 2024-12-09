class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>presum(nums.size(),0);
        int check = -1;
        if(nums[0]%2==0) {check=0;}
        else{check=1;}
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==0){
                if(check==0){
                    presum[i]=presum[i-1]+1;
                }
                else{
                    presum[i]=presum[i-1];
                }
                check=0;
            }
            else{
                if(check==1){
                    presum[i]=presum[i-1]+1;
                }
                else{
                    presum[i]=presum[i-1];
                }
                check=1;
            }
        }
        for(int j=0;j<queries.size();j++){
            int start=queries[j][0];
            int end=queries[j][1];
            if(presum[end]-presum[start]==0){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};