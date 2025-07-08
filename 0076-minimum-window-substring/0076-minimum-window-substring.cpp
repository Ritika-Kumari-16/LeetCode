class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int n = s.size();
        int m= t.size();
        for(auto it :t){
            mpp[it]++;
        }
        int l=0 , r=0;
        int count=0;
        int idx=-1;
        int minlen=INT_MAX;
        while(r<n){
            if(mpp[s[r]]>0) count++;
            mpp[s[r]]--;
            while(count==m){
                if((r-l+1) < minlen){
                    minlen= r-l+1;
                    idx=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) count --;
                l++;
            }
            r++;
        }
        return idx==-1? "" :s.substr(idx,minlen);
    }
};