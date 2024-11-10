class Solution {
public:
    int leastfreqq( vector<int> & freq){
        int minimum=INT_MAX;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) continue;
            else {
                minimum=min(freq[i],minimum);
            }
        }
        return minimum;
    }
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            vector<bool>visited(26,0);
            int count =0;
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(visited[s[j]-'a']==0){
                    count ++;
                    visited[s[j]-'a']=1;
                }
                if(count>=2){
                    int mostfreq=*max_element(freq.begin(),freq.end());
                    int leastfreq= leastfreqq(freq);
                    ans+=(mostfreq-leastfreq);
                }
            }
        }
        return ans;
    }
};