class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>temp(26,0);
        int maxfreq=0;
        int maxfreqcnt=0;
        for(int i=0;i<tasks.size();i++){
            temp[tasks[i]-'A']++;
            if(maxfreq<temp[tasks[i]-'A']){
                maxfreq=temp[tasks[i]-'A'];
            }
        }
        for(int i=0;i<26;i++){
            if(temp[i]==maxfreq) maxfreqcnt++;
        }
        int time = (maxfreq-1)*(n+1)+maxfreqcnt;
        int t= tasks.size();
        return max(time,t);
    }
};