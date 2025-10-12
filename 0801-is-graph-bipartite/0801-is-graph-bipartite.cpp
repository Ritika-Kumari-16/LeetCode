class Solution {
public:
bool dfs(int node , vector<vector<int>>&graph , vector<int>&color , vector<int>&visited , int initclr){
    color[node]=initclr;
    visited[node]=1;
    for(auto it:graph[node]){
        if(color[it]==initclr) return false;
        if(!visited[it]){
            if(dfs(it,graph,color,visited,!initclr)==false) return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int N= graph.size();
        vector<int>color(N,-1);
        vector<int>visited(N,0);
        for(int i=0;i<N;i++){
            if(!visited[i]){
                if(dfs(i,graph,color,visited,0)==false) return false;
            }
        }
        return true;
    }
};