class Solution {
public:
    bool allcapitals(string s){
        for(char &ch:s){
            if(ch<'A' || ch>'Z') return false;
        }
        return true;
    }
    bool allsmall(string s){
        for(char &ch : s){
            if(ch<'a' || ch>'z'){
                return false;
            }
            
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(allcapitals(word) || allsmall(word) || allsmall(word.substr(1))){
            return true;
        }

        return false;
    }
};