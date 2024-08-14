class Solution {
public:
    bool isPalindrome(string &s, int start , int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int ind,string &s,vector<vector<string>>&ans, vector<string >& path , int n){
        if(ind==n){ ans.push_back(path);
        return ;}
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,path,n);
                path.pop_back();

            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string > path;
        int n=s.size();
        solve(0,s,ans,path,n);
        return ans;
    }
};