class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        int count=0;
        vector<int>hash(3,-1);
        for(int r=0;r<n;r++){
            hash[s[r]-'a']=r;
            if(hash[0] !=-1 && hash[1]!=-1 && hash[2]!=-1){
                int val = 1+min(hash[0], min(hash[1],hash[2]));
                count+=val;
            }
        }
        return count;
    }
};