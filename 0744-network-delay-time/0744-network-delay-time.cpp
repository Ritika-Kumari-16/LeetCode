class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int src) {
        vector<pair<int,int>>adj[N+1];
        for(auto it:times)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        vector<int>dist(N+1, 1e9);
        
        queue<int>q;
        q.push(src);
        dist[src]=0;
        dist[0]=0;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            int distance = dist[front];
            
            for(auto neigh: adj[front])
            {
                int newd = distance + neigh.second;
                if(newd<dist[neigh.first])
                {
                    q.push(neigh.first);
                    dist[neigh.first]=newd;
                }
            }
        }
    
        
        int ans = -1;
        for(int i=1;i<=N;i++)
        {
            if(dist[i]==1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};