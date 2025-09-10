class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int maxlen=1;
        for(auto it:mpp){
            if(mpp.find(it.first-1)==mpp.end()){
                int len=1;
                int x=it.first+1;
                while(mpp.find(x)!=mpp.end()){
                    len++;
                    maxlen=max(maxlen,len);
                    x++;
                }
            }
        }
        return maxlen;
    }
};