class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int n= s.size();
        int m= t.size();
        int minlen= INT_MAX;
        int cnt=0;
        int sind=-1;
        vector<int>hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    sind=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;


        }
        return sind==-1 ? "" : s.substr(sind,minlen);
    }
};