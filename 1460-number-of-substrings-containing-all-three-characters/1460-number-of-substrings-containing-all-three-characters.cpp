class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n= s.size();
        int l=0,r=0;
        unordered_map<char,int>freq;
        while(r<n){
            freq[s[r]]++;
            while(freq.size()==3){
                count+=(n-r);
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            r++;
        }
        return count;
    }
};