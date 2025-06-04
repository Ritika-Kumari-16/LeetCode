class Solution {
public:
    bool isvalid( int row, int col ,vector<vector<int>>& grid , int n ){
        return row>=0 && row<n && col >=0 && col<n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        int dr[]={-1,0,0,1}; 
        int dc[]={0,-1,1,0};
        int leastTime=0;
        while(!pq.empty()){
            int time= pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            leastTime=max(leastTime,time);
            pq.pop();
            if(row==n-1 && col==n-1) return leastTime;
            for(int i=0;i<4;i++){
                int nrow= row+dr[i];
                int ncol= col+dc[i];
                if(isvalid(nrow,ncol,grid ,n ) && visited[nrow][ncol]==0){
                    pq.push({grid[nrow][ncol],{nrow,ncol}});
                    visited[nrow][ncol]=1;
                }
            }

        }

        return -1;
    }
};