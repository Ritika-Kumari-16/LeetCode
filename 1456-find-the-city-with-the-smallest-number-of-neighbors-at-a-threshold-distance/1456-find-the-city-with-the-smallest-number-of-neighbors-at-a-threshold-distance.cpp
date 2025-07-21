class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adjmatrix(n,vector<int>(n,1e9));
        for(auto it:edges){
            adjmatrix[it[0]][it[1]]=it[2];
            adjmatrix[it[1]][it[0]]=it[2];
            
        }
        for(int i=0;i<n;i++){
            adjmatrix[i][i]=0;
        }
        for(int viaroute=0;viaroute<n;viaroute++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adjmatrix[i][viaroute]<1e9 && adjmatrix[viaroute][j]<1e9){
                        adjmatrix[i][j]=min(adjmatrix[i][j] , adjmatrix[i][viaroute]+adjmatrix[viaroute][j]);
                    }
                }
            }
        }
        int mincnt=n;
        int city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(adjmatrix[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=mincnt){
                mincnt=cnt;
                city=i;
            }
        }
        return city;
    }
};