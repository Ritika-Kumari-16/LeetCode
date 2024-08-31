class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int time=0;
        int delrow[]={-1,0,0,+1};
        int delcol[]={0,-1,+1,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if(nr<n&&nr>=0&&nc<m&&nc>=0&& grid[nr][nc]==1 && vis[nr][nc]==0){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                    }
                }
            }
        return time;
        
    }
};