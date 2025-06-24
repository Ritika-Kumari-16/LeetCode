class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        unordered_map<char,int>mpp;
        int n= s.size();
        int maxlen=1;
        int l=0;
        int r=0;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                int idx= mpp[s[r]];
                l=max(l,idx+1);
            }
            mpp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};