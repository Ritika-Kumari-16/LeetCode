class Solution {
public:
    bool is_vowel(char &ch){
        if(ch== 'a' || ch== 'e' || ch== 'i' || ch == 'o' || ch =='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m= queries.size();
        vector<int>cumm(n,0);
        vector<int>result(m,0);
        int sum=0;
        for(int i=0;i<n;i++){
            int s=words[i].size();
            if(is_vowel(words[i][0]) && is_vowel(words[i][s-1])){
                sum++;
            }
            cumm[i]=sum;
        }
        for(int i =0;i<m;i++){
            int start= queries[i][0];
            int end= queries[i][1];
            result [i]= cumm[end] - ((start>0) ? cumm[start-1] : 0);
        }
        return result;
        
    }
};