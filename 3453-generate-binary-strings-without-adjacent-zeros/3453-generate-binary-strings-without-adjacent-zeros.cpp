class Solution {
public:
    void solve(int n , string &temp , vector<string>&result){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }
        //take 1
        temp+='1';
        solve(n, temp,result);
        temp.pop_back();
        //take 0
        if(temp.empty() || temp.back()!='0'){
            temp.push_back('0');
            solve(n,temp,result);
            temp.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string>result;
        string temp="";
        solve(n,temp,result);
        return result;
        
    }
};