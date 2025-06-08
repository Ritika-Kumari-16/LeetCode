class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        int l=0,r=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()==3){
                cnt+=(n-r);
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;

            }
            r++;
        }

        return cnt;
    }
};