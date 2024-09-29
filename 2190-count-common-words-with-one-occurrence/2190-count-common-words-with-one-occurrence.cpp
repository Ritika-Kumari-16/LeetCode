class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mpp;
     
        int cnt=0;
        for(auto str:words1) mpp[str]++;

        for(auto i:words2)
            if(mpp.find(i)!=mpp.end() && mpp[i]<=1) mpp[i]--;
        
        for(auto it:mpp)
            if(it.second==0)cnt++;
        
        return cnt;
    }
};