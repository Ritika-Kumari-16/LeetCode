class Solution {
public:
void dfs(int i, vector<int>&visited , vector<vector<int>>&adjlist){
    visited[i]=1;
    for(auto &it: adjlist[i]){
        if(!visited[it]){
            dfs(it,visited,adjlist);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjlist(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        int countprovinces=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                countprovinces++;
                dfs(i,visited,adjlist);
            }
        }
        return countprovinces;
    }
};