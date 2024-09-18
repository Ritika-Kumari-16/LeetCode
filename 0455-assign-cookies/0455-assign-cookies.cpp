class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size();
        int m=s.size();
        int count=0;
        int i=0;
        int j=0;
        while(n>i && m>j){
            if(g[i]<=s[j]){
                count++;
                i++,j++;
                }
            else if(g[i]>s[j]){
                j++;
            }

        }
        return count;
        
    }
};