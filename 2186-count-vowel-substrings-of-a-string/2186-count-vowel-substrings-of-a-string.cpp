class Solution {
public:
    int countVowelSubstrings(string word) {
        int count=0;
        for(int j=0;j<word.size();j++){
            unordered_map<char,int>mp;
            mp.clear();
            for(int i=j;i<word.size();i++){
                if(word[i] =='a' ||word[i] =='e' ||word[i] =='i' ||word[i] =='o' || word[i] =='u'){
                    mp[word[i]]++;
                }
                else{
                    break;
                }
                if(mp.size()==5) {count++;}
            }
        }
        return count;
    }
};