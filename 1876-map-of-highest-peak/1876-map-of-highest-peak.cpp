class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m= isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[4]={-1,0,0,1};
        int delcol[4]={0,-1,1,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int height=q.front().second;
            ans[row][col]=height;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] ==0 && isWater[nrow][ncol] ==0){
                    q.push({{nrow,ncol},height+1});
                    visited[nrow][ncol]=1;
                }
            }

        }
        return ans;
    }
};