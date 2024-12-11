class Solution {
public:
    unordered_map<string,bool>mp;
    bool isconcatenated(string word , unordered_set<string>&st){
        if(mp.find(word)!=mp.end()) return mp[word];
        int l=word.size();

        for(int i=0;i<l;i++){
            string prefix = word.substr(0,i+1);
            string suffix=word.substr(i+1);
            if(st.find(prefix)!=st.end() && st.find(suffix)!=st.end() || st.find(prefix)!=st.end() && isconcatenated(suffix,st)){
                return mp[word]=true;
            }
        }
        return mp[word]= false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        int n = words.size();
        unordered_set<string>st(begin(words),end(words));
        vector<string>ans;
        for(int i=0;i<n;i++){
            string word=words[i];
            if(isconcatenated(word,st)){
                ans.push_back(word);
            }
        }

        return ans;
    }
};