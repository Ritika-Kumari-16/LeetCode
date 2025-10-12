class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int freshoranges=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) freshoranges++;
                else if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    visited[i][j]=1;
                }
            }
        }
        int count=0;
        int maxtime=0;
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            maxtime=max(maxtime,it.first);
            for(int i=0;i<4;i++){
                int nrow= delrow[i]+it.second.first;
                int ncol=delcol[i]+it.second.second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    int time=it.first;
                    q.push({it.first+1,{nrow,ncol}});
                    count++;
                }
            }
        }
        return (count==freshoranges)? maxtime: -1;
    }
};