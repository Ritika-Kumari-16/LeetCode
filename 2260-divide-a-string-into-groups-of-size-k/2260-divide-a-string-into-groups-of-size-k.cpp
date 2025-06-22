class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp="";
        int n= s.size();
        int i=0;
        while(i<n){
            if(i+k-1 <n ){
                ans.push_back(s.substr(i,k));
            }
            else{
                break;
            }
            i+=k;
        }
        if(i<n){
            while(i<n){
                    temp.push_back(s[i]);
                    i++;
            }
            while(temp.size()<k){
                    temp+=fill;
            }
            ans.push_back(temp);
    }
        return ans;
        
    }
};