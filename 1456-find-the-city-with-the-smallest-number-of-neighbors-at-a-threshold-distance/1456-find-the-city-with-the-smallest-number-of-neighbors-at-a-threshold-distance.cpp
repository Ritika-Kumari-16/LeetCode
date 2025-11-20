class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            dist[u][u]=0;
            dist[v][v]=0;
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        for(int viaroute=0;viaroute<n;viaroute++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][viaroute]!=1e9 && dist[viaroute][j]!=1e9){
                        dist[i][j]=min(dist[i][j],dist[i][viaroute]+dist[viaroute][j]);
                    }
                }
            }
        }
        int city=0;
        int mincnt=1e9;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mincnt){
                mincnt=count;
                city=i;
            }
        }
        return city;
    }
};