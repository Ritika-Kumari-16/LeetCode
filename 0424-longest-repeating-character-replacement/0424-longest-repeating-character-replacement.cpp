class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        vector<int>freqarr(26,0);
        int maxfreq=0;
        int maxlen=0;
        int n = s.size();
        while(r<n){
            freqarr[s[r]-'A']++;
            if(freqarr[s[r]-'A']>maxfreq){
                maxfreq=freqarr[s[r]-'A'];
            }
            if((r-l+1)-maxfreq >k){
                freqarr[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,freqarr[i]);
                }
                l++;
            }
            int len=r-l+1;
            if(len-maxfreq <=k){
                maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};