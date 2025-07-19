class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int,int>>>adj(n);
        for(auto &it :flights){
            adj[it[0]].push_back({it[1],it[2]});
            }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<int>ans(n,INT_MAX);
        pq.push({0,{0,src}});
        ans[src]=0;
        while(!pq.empty()){
            int kval=pq.top().first;
            int price=pq.top().second.first;
            int node =pq.top().second.second;
            pq.pop();
            if(kval>k) continue;
            for(auto &it: adj[node]){
                int adjnode= it.first;
                int adjprice=it.second;
                if(kval<=k && ans[adjnode]>price+adjprice){
                    ans[adjnode]=price+adjprice;
                    pq.push({kval+1,{ans[adjnode],adjnode}});
                }
            }
        }
        return ans[dst]==INT_MAX ? -1 :ans[dst];
    }
};