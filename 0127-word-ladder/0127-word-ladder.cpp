class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        if(beginWord==endWord) return 1;
        int level=1;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string word=q.front();
                q.pop();
                for(int j=0;j<word.size();j++){
                    char org= word[j];
                    for(int k=0;k<26;k++){
                        word[j]='a'+k;
                        if(st.find(word)!=st.end()){
                            if(word==endWord) return level+1;
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[j]=org;
                }
            }
            level++;
        }
        return 0;
    }
};