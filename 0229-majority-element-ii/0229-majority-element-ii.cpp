class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maxel1=-1;
        int maxel2=-1;
        int cnt1=0 , cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=maxel2){
                maxel1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && maxel1!=nums[i]){
                maxel2=nums[i];
                cnt2++;
            }
            else if(nums[i]==maxel1) cnt1++;
            else if(nums[i]==maxel2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxel1) cnt1++;
            if(nums[i]==maxel2) cnt2++;
        }
        if(cnt1>nums.size()/3) ans.push_back(maxel1);
        if(cnt2>nums.size()/3) ans.push_back(maxel2);
        return ans;
    }
};