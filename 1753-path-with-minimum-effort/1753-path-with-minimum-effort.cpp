class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        distance[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int row[]={-1,0,0,1};
        int col[]={0,-1,1,0};
        while(!pq.empty()){
            auto it = pq.top();
            int dist= it.first;
            int r= it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1) return dist;
            pq.pop();
            for(int i=0;i<4;i++){
                int newr=r+row[i];
                int newc=c+col[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int diff= abs(heights[r][c]-heights[newr][newc]);
                    int newdis=max(diff,dist);
                    if(newdis < distance[newr][newc]){
                        distance[newr][newc]=newdis;
                        pq.push({newdis,{newr,newc}});
                    }
                }
            }

        }
        return distance[n-1][m-1];
    }
};