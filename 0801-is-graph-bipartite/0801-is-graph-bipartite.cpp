class Solution {
public:
bool dfs(int node , int color , vector<int>&colournodes ,vector<vector<int>>& graph ){
    colournodes[node]=color;
    for(auto &it : graph[node]){
        if(colournodes[it]!=-1 && colournodes[it]==color){
            return true;
        }
        else if(colournodes[it]==-1){
            if(dfs(it,!color, colournodes,graph)){
                return true;
            }
        }
    }
    return false;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph .size();
        vector<int>colournodes(n,-1);
        int color=0;
        for(int i=0;i<n;i++){
            if(colournodes[i]==-1){
                if(dfs(i,color,colournodes,graph)){
                    return false;
                }
                color=!color;
            }
        }
        return true;
    }
};