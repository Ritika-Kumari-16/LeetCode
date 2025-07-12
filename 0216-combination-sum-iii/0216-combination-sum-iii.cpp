class Solution {
public:
void solve(int i ,int j,int sum, int k , int n , vector<int>&temp , vector<vector<int>>&ans){
    if(i==k){
        if(sum==n) {
            ans.push_back(temp);
        }
        return;
    }
    for(int num=j;num<=9;num++){
        if(sum+num>n) break;
        temp.push_back(num);
        solve(i+1,num+1,sum+num,k,n,temp,ans);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,1,0,k,n,temp,ans);
        return ans;
    }
};