class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        for(auto &it:brokenLetters){
            st.insert(it);
        }
        int count=0;
        bool found=false;
        int i=0;
        int n= text.size();
        while(i<n){
            found=false;
            while(i<n && text[i]!=' '){
                if(st.count(text[i])>0){
                    found=true;
                }
                i++;
            }
            if(!found) count++;
            i++;
        }
        return count;
    }
};