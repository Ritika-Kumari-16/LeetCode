class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            int idx=word1[i]-'a';
            int idx1=word2[i]-'a';
            freq1[idx]++;
            freq2[idx1]++;

        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0) continue;
            if(freq1[i]==0 && freq2[i]==0) continue;
            else return false;
        }
        sort(freq1.begin(),freq1.end());
        sort(begin(freq2),end(freq2));
        return freq1==freq2;
    }
};