class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int t=tasks.size();
        int maxfreq=0;
        int maxfreqcount=0;
        vector<int>freq(26,0);
        for(auto it:tasks){
            freq[it-'A']++;
            if(maxfreq<freq[it-'A']){
                maxfreq=freq[it-'A'];
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]==maxfreq) maxfreqcount++;
        }
        int miniintervals= (maxfreq-1)*(n+1)+maxfreqcount;
        return max(miniintervals,t);
    }
};