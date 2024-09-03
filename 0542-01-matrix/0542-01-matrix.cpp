class Solution {
public:
    //using DFS for this problem can lead to inefficiency and stack overflow 
    //issues due to deep recursion, especially in large matrices. A more 
    //appropriate approach would be to use Breadth-First Search (BFS)

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size(), n=mat[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        queue<pair<int, pair<int, int>>> q;
        // {dist, {x, y}}
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({0, {i, j}});
                    vis[i][j]=1;
                } else vis[i][j]=0;
            }
        }

        int dirx[]={1,0,-1,0};
        int diry[]={0,-1,0,1};

        while(!q.empty()){
            auto pq = q.front(); q.pop();
            
            int dist=pq.first;
            int x=pq.second.first;
            int y=pq.second.second;

            for(int i=0; i<4; i++){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    q.push({dist+1, {nx, ny}});
                    vis[nx][ny]=1;
                    mat[nx][ny]=dist+1;
                }
            }
        }
        return mat;
    }
};