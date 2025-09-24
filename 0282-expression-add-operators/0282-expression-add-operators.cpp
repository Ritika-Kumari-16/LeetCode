class Solution {
public:
void helper(int i , string &num , int target, long eval , long residual , string temp, vector<string>&ans){
    if(i==num.size()){
        if(eval==target){
            ans.push_back(temp);
        }
        return;
    }
    string s;
    long val=0;
    for(int j=i;j<num.size();j++){
        if(j>i && num[i]=='0') return;
        s+=num[j];
        val=val*10+(num[j]-'0');
        if(i==0){
            helper(j+1,num,target,val,val,s,ans);
        }
        else{
            helper(j+1,num,target,eval+val,val,temp+'+'+s , ans);
            helper(j+1,num,target,eval-val,-val,temp+'-'+s , ans);
            helper(j+1,num,target,(eval-residual)+(residual*val),residual*val,temp+'*'+s , ans);
        }
    }
}
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        string temp="";
        helper(0,num,target,0,0,temp,ans);
        return ans;
    }
};