class Solution {
public:
    bool ispreandsuf(string str1 , string str2){
        if(str1.size()>str2.size()) return false;
        if(str1.size()==str2.size()) {
            if(str1==str2) return true;
            return false;
        }
        int n=str1.size();
        int m = str2.size();
        if(str1==str2.substr(0,n) && str1==str2.substr(m-n,n)) return true;
        return false;

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ispreandsuf(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};