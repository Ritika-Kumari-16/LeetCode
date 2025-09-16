class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        unordered_map<char,int>mpps;
        int n=s.size();
        int m=t.size();
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        int x=mpp.size();
        int minlen=INT_MAX;
        int idx;
        int k=0;
        int l=0,r=0;
        while(r<n){
            mpps[s[r]]++;
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=mpps[s[r]]){
                k++;
            }
            while(k==m){
                if(minlen>(r-l+1)){
                    minlen=r-l+1;
                    idx=l;
                }
                mpps[s[l]]--;
                if(mpp.find(s[l])!=mpp.end() && mpps[s[l]]<mpp[s[l]]){
                    k--;
                }
                l++;
            }
            r++;
        }
        return minlen==INT_MAX? "" : s.substr(idx,minlen);
    }
};