class Solution {
public:
int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:roads){
            int from=it[0];
            int to=it[1];
            int time=it[2];
            graph[from].push_back({to,time});
            graph[to].push_back({from,time});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        vector<int>ways(n,0);
        ways[0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long time=it.first;
            int node=it.second;
            for(auto adj:graph[node]){
                int adjnode= adj.first;
                int adjtime=adj.second;
                if(dist[adjnode]>adjtime+time){
                    dist[adjnode]=time+adjtime;
                    ways[adjnode]=ways[node];
                    pq.push({dist[adjnode],adjnode});
                }
                else if(dist[adjnode]==adjtime+time){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};