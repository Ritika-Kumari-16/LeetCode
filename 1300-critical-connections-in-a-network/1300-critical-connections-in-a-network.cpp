class Solution {
public:
    int timestamp=1;
    void dfs( int node ,int parent ,vector<vector<int>>&adjlist,vector<int>&time , vector<int>&minitime , vector<int>&visited , vector<vector<int>>&criticaledges ){
        visited[node]=1;
        time[node]=timestamp;
        minitime[node]=timestamp;
        timestamp++;
        for(auto adjnode : adjlist[node]){
            if(adjnode==parent) continue;
            if(visited[adjnode]==0){
                dfs(adjnode ,node , adjlist , time , minitime , visited , criticaledges);
                minitime[node]=min(minitime[node],minitime[adjnode]);
                if(minitime[adjnode]>time[node]){
                criticaledges.push_back({node,adjnode});
                }
            }
            else{
                minitime[node]=min(minitime[node],time[adjnode]);
            }

        }


    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //make the graph
        vector<vector<int>>adjlist(n);
        for(auto &it : connections){
            int u = it[0];
            int v= it[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int>time(n,-1);
        vector<int>minitime(n,-1);
        vector<int>visited(n,0);
        vector<vector<int>>criticaledges;
        dfs(0,-1,adjlist,time,minitime,visited,criticaledges);
        return criticaledges;
    }
};