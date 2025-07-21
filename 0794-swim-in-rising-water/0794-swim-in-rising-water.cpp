class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        while(!pq.empty()){
            int time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==n-1) return time;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if( nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol]){
                    visited[nrow][ncol]=1;
                    int maxtime=max(time,grid[nrow][ncol]);
                    pq.push({maxtime,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};