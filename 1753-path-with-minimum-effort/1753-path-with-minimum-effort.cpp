class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        vector<vector<int>>effortmat(n,vector<int>(m,1e9));
        effortmat[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto [effort,cell]=pq.top();
            pq.pop();
            int row=cell.first;
            int col=cell.second;
            if(row==n-1 && col==m-1) return effort;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int val=abs(heights[nrow][ncol]-heights[row][col]);
                    int mineffort= max(effort,val);
                    if(effortmat[nrow][ncol]> mineffort){
                        effortmat[nrow][ncol]=mineffort;
                        pq.push({mineffort,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};