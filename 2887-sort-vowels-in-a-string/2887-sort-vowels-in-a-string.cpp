class Solution {
public:
bool isvowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' ||c == 'o' ||c == 'u' || c == 'A' ||c == 'E' ||c == 'I' ||c == 'O' ||c == 'U'){
        return true;
    }
    return false;
}
    string sortVowels(string s) {
        vector<int>lowerfreq(26,0);
        vector<int>upperfreq(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i]-65>=0 && s[i]-65<26){
                upperfreq[s[i]-65]++;
            }
            else{
                lowerfreq[s[i]-97]++;
            }
        }
        vector<char>vowels;
        for(int i=0;i<26;i++){
            if(isvowel(i+'A') && upperfreq[i]>0){
                for(int j=0;j<upperfreq[i];j++){
                    vowels.push_back(i+'A');
                }
            }
        }
        for(int i=0;i<26;i++){
            if(isvowel(i+'a') && lowerfreq[i]>0){
                for(int j=0;j<lowerfreq[i];j++){
                    vowels.push_back(i+'a');
                }
            }
        }
        string ans;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                ans.push_back(vowels[j]);
                j++;
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};