class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int time=0;
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        while(!q.empty()){
            int size=q.size();
            bool changed=false;
            for(int i=0;i<size;i++){
                int row= q.front().first;
                int col=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nrow=row+drow[j];
                    int ncol=col+dcol[j];
                    if(nrow<0 || nrow >=n || ncol<0 || ncol>=m || grid[nrow][ncol]==0 || grid[nrow][ncol]==2 || visited[nrow][ncol]) continue;
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    changed=true;
                }
                
            }
            if(changed) time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]) return -1;
            }
        }
        return time;
    }
};