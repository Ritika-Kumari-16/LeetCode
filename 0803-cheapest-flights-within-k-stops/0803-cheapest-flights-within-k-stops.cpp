class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it : flights){
            int from = it[0];
            int to=it[1];
            int cost=it[2];
            graph[from].push_back({to,cost});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>pq;
        //pq{cost,node,stops};
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto [cost,nodestops]=pq.front();
            pq.pop();
            int node= nodestops.first;
            int kval=nodestops.second;
            if(kval>k) continue;
            for(auto it: graph[node]){
                int price= it.second;
                int adjnode= it.first;
                if(dist[adjnode]>cost+price){
                    dist[adjnode]=cost+price;
                    pq.push({cost+price,{adjnode,kval+1}});
                }
            }
        }
        return (dist[dst]==1e9)? -1 :dist[dst];
    }
};