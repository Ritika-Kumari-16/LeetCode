class Solution {
private:
    bool bfs(int node, vector<int>&col , vector<vector<int>>&graph){
        queue<int>q;
        q.push(node);
        col[node]=0;
        while(!q.empty()){
            int start=q.front();
            q.pop();
            for( auto it : graph[start]){
                if(col[it]==-1){
                    col[it]=!col[start];
                    q.push(it);
                }
                else if( col[it]==col[start]) return false;
            }
        }
        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(bfs(i,col,graph)==false) return false;
            }

        }
        return true;
        
    }
};