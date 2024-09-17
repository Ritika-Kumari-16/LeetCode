class Solution {
public:
    const long long mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>distance(n,LLONG_MAX);
        vector<long long>ways(n,0);
        distance[0]=0;
        ways[0]=1;
        priority_queue<pair<long long ,long long>,vector<pair<long long , long long>>,greater<pair<long long , long long>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long dist=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it :adj[node]){
                long long pathdis=it.second;
                long long adjnode=it.first;
                if(dist+pathdis<distance[adjnode]){
                    distance[adjnode]=dist+pathdis;
                    ways[adjnode]=ways[node];
                    pq.push({dist+pathdis,adjnode});
                }
                else if(dist+pathdis==distance[adjnode]){
                    ways[adjnode]+=ways[node]%mod;
                }
            }
        }
        if(distance[n-1]==1e9){
            return -1;
        }
        else{
            return ways[n-1]%mod;
        }
    // return ways[n-1]%mod ;
        
    }
};