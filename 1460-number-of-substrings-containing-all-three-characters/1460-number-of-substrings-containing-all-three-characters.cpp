class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0,count=0;
        vector<int>mpp(3,0);
        while(r<n){
            mpp[s[r]-'a']++;
            while(mpp[0]>0 && mpp[1]>0 && mpp[2]>0){
                count+=n-r;
                mpp[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};