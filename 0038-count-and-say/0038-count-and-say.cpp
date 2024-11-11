class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string say = countAndSay(n-1);
        string ans="";
        int i=0;
        while(i<say.size()){
            char ch=say[i];
            int count=0;
            while(i<say.size()){
                if(say[i]!=ch) break;
                count++;
                i++;
            }
            ans= ans + to_string(count)+string (1,ch);
        }
        return ans;
    }
};