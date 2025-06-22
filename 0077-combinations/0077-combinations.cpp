class Solution {
public:
    void solve(int i , int n , int k , vector<int>&temp ,vector<vector<int>>&ans){
        if(temp.size()==k) {
            ans.push_back(temp);
            return ;
        }
        if(i>n) return ;
        //take it 
        temp.push_back(i);
        solve(i+1,n,k,temp,ans);
        temp.pop_back();
        // not take it
        solve(i+1,n,k,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        if(n==0) return ans;
        solve(1,n,k,temp,ans);
        return ans;
        
    }
};