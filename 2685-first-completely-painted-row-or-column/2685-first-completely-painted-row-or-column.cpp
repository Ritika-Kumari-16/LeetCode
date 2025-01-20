class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>mp;
        int n = mat.size();
        int m= mat[0].size();
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int minind=INT_MAX;
        for(int row=0;row<n;row++){
            int maxind=INT_MIN;
            for(int col=0;col<m;col++){
                int val=mat[row][col];
                maxind=max(maxind,mp[val]);
            }
            minind=min(minind,maxind);
        }
        for(int col=0;col<m;col++){
            int maxind=INT_MIN;
            for(int row=0;row<n;row++){
                int val=mat[row][col];
                maxind=max(maxind,mp[val]);
            }
            minind=min(minind,maxind);
        }
        return minind;
    }
};