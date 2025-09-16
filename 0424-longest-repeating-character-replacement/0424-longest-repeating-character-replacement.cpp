class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int l=0;
        int r=0;
        vector<int>freq(26,0);
        int maxfreq=0;
        int maxlen=0;
        while(r<n){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            while((r-l+1)-maxfreq>k){
                freq[s[l]-'A']--;
                l++;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,freq[i]);
                }
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};