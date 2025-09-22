class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mpp;
        int maxfreq=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            maxfreq=max(maxfreq,mpp[nums[i]]);
        }
        int ans=0;
        for(auto it: mpp){
            if(it.second==maxfreq) ans+=maxfreq;
        }
        return ans;
    }
};