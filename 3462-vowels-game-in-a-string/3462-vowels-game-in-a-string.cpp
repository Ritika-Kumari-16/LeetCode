class Solution {
public:
bool isvowel(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
    bool doesAliceWin(string s) {
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])) return true;
        }
        return false;
    }
};