class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
        if(grid[0][0] ==1 || grid[n-1][n-1]==1) return -1;
        ans[0][0]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int drow[]={-1,-1,-1,0,0,0,1,1,1};
        int dcol[]={-1,0,1,-1,0,1,-1,0,1};
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if(row == n-1 && col == n-1){
                return dist;}
            pq.pop();
            for(int i=0;i<9;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow==row && ncol==col) continue;
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=n || grid[nrow][ncol]==1 ){
                    continue;
                }
                if(ans[nrow][ncol]> dist+1){
                    ans[nrow][ncol]=dist+1;
                    pq.push({dist+1,{nrow,ncol}});
                }
            }
        }

        return  -1;
    }
};