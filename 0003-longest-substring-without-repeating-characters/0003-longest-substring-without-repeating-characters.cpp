class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen=0;
        unordered_map<char,int>mpp;
        int l=0;
        int r=0;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                int idx=mpp[s[r]];
                if(l<=idx){
                    l=idx+1;
                }
            }
            mpp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};