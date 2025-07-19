class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>mintime(n+1,INT_MAX);
        mintime[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                if(mintime[it.first]>it.second+time){
                    mintime[it.first]=it.second+time;
                    pq.push({mintime[it.first],it.first});
                }
            }
        }
        int mini=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(mintime[i]==INT_MAX) return -1;
            mini=max(mini,mintime[i]);
        }
        return mini;
    }
    
};