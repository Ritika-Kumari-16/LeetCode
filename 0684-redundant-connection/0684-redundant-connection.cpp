class Solution {
public:
    bool dfs( int u , int v, unordered_map<int,vector<int>>&adjlist , vector<bool>&visited){
        visited[u]=true;
        if(u==v) return true;
        for( auto it: adjlist[u]){
            if(visited[it]==false){
                if(dfs(it,v,adjlist,visited)) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adjlist;
        int n = edges.size();
        for(int i=0;i<n;i++){
            int u= edges[i][0];
            int v= edges[i][1];
            vector<bool>visited(n+1,false);
            if(adjlist.find(u)!=adjlist.end() && adjlist.find(v)!=adjlist.end() && dfs(u,v,adjlist,visited)){
                return edges[i];
            }
            adjlist[v].push_back(u);
            adjlist[u].push_back(v);

        }
        return {};
    }
};