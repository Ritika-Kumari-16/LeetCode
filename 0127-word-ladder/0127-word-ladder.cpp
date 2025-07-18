class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto &word: wordList){
            st.insert(word);
        }
        if(st.find(endWord)==st.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word= q.front().first;
            int dist=q.front().second;
            q.pop();
            if(word==endWord) return dist;
            for(int i=0;i<word.size();i++){
                char original =word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,dist+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};