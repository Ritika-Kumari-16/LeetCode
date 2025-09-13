class Solution {
public:
bool isvowel(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
        int maxvowelfreq=0;
        int maxconsonentfreq=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            if(isvowel(s[i])){
                maxvowelfreq=max(maxvowelfreq,freq[s[i]-'a']);
            }
            else{
                maxconsonentfreq=max(maxconsonentfreq,freq[s[i]-'a']);
            }
        }
        return maxvowelfreq+maxconsonentfreq;
    }
};