class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it: times){
            int from= it[0];
            int to=it[1];
            int time=it[2];
            graph[from].push_back({to,time});
        }
        vector<int>totaltime(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        totaltime[k]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int time=it.first;
            pq.pop();
            for(auto adj:graph[node]){
                int adjnode= adj.first;
                int adjtime=adj.second;
                if(totaltime[adjnode]>adjtime+time){
                    totaltime[adjnode]=adjtime+time;
                    pq.push({totaltime[adjnode],adjnode});
                }
            }
        }
        int mintime=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(totaltime[i]==1e9) return -1;
            mintime=max(totaltime[i],mintime);
        }
        return mintime;
    }
};