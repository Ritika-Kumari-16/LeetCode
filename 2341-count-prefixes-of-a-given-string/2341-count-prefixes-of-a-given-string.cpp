class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt=0;
        for(int i =0;i<words.size();i++){
            if( s.substr(0, words[i].size())== words[i]){
                cnt++;
            }
        }
        return cnt;
        
    }
};