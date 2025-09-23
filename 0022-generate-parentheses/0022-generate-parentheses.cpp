class Solution {
public:
void generate(int o , int c, int n, string &temp , vector<string>&ans){
    if(temp.size()== 2*n && o==c){
        ans.push_back(temp);
        return ;
    }
    if(o<n){
        temp+='(';
        generate(o+1,c,n,temp,ans);
        temp.pop_back();
    }
    if(c<o){
        temp+=')';
        generate(o,c+1,n,temp,ans);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        generate(0,0,n,temp,ans);
        return ans;
        
    }
};