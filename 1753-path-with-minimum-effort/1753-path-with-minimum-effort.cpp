class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m){
                    continue;
                }
                int val=max(ans[row][col] , abs(grid[row][col]-grid[nrow][ncol]));
                if(ans[nrow][ncol]> val){
                    ans[nrow][ncol]=val;
                    pq.push({val,{nrow,ncol}});
                }
            }
        }

        return ans[n-1][m-1];
        
    }
};