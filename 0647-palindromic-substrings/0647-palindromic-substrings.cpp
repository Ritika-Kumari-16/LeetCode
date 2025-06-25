class Solution {
public:
    int expand(int left , int right , string s){
        int count=0;
        while(left>=0 && right <s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalstrings=0;
        for(int i=0;i<s.size();i++){
            int odd= expand(i,i,s);
            totalstrings+=odd;
            int even= expand(i,i+1,s);
            totalstrings+=even;

        }
        return totalstrings;
    }
};