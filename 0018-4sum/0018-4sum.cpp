class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i,j;
        for (i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for(j=i+1;j<nums.size();j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
            int k = j + 1;
            int l = nums.size() - 1;

            while (k < l) {
                long long total = nums[i] + nums[j];
                total+=+ nums[k];
                total+=nums[l];

                if (total > target) {
                    l--;
                } else if (total < target) {
                    k++;
                } else {
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    res.push_back(temp);
                    k++;
                    l--;
                    while(k<l&&nums[k]==nums[k-1]){
                        k++;
                    }
                    while(k<l&&nums[l]==nums[l+1]){
                        l--;
                    }
                    }
                }
            }
        }
        return res;
        }
};