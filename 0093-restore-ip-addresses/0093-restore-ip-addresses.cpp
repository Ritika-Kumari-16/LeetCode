class Solution {
public:
    int n;
    vector<string>ans;
    bool isvalid(string s){
        if(s[0]=='0'){
            return false;
        }
        int val= stoi(s);
        if(val>0 && val<=255){
            return true ;
        }
        return false;
    }
    void solve( string &s , int idx , int parts , string curr ){
        if(idx==n && parts==4){
            curr.pop_back();
            ans.push_back(curr);
            return ;
        }
        if(idx+1<=n){
            solve(s , idx+1, parts+1 , curr + s.substr(idx,1)+".");
        }
        if(idx+2<=n && isvalid(s.substr(idx,2))){
            solve(s,idx+2,parts+1, curr + s.substr(idx,2)+".");
        }
        if(idx+3<=n && isvalid(s.substr(idx,3))){
            solve(s,idx+3,parts+1, curr + s.substr(idx,3)+".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n=s.size();
        if(n>12){
            return {};
        }
        string curr="";
        int parts=0;
        solve(s,0,parts,curr);
        return ans;


        
    }
};