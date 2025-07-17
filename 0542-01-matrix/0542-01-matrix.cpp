class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m= mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    visited[i][j]=1;
                }
            }
        }
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        while(!q.empty()){
            int dist=q.front().first;
            int row= q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow<0 || ncol<0 || nrow>=n || ncol>=m || visited[nrow][ncol] || mat[nrow][ncol]==0) continue;
                q.push({dist+1,{nrow,ncol}});
                visited[nrow][ncol]=1;
                mat[nrow][ncol]=dist+1;
            }

        }
        return mat;
    }
};