class Solution {
public:
    void solve(int i , int k , int n , int sum , vector<int>temp , vector<vector<int>>&result){
        if(temp.size()==k){
            if(sum==n) result.push_back(temp);
            return ;
        }
        for(int val=i;val<=9;val++){
            if(temp.size()<k && sum+val<=n){
                temp.push_back(val);
                solve(val+1,k,n,sum+val,temp,result);
                temp.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(1,k,n,0,temp,result);
        return result;
    }
};