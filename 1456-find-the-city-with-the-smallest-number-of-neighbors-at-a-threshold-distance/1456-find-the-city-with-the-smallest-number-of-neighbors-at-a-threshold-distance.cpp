class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,-1));
        for(auto it : edges){
            int u= it[0];
            int v=it[1];
            int wt=it[2];
            mat[u][v]=wt;
            mat[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    mat[i][j]=0;
                    
                }
                if(mat[i][j]==-1){
                    mat[i][j]=1e8;
                }
            }
        }
        for( int via=0; via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j], mat[i][via]+mat[via][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    mat[i][j]=0;
                    
                }
                if(mat[i][j]==1e8){
                    mat[i][j]=-1;
                }
            }
        }
        int cityno=-1;
        int cntcity = n+1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    cnt++;

                }

            }
            if(cnt<=cntcity){
                    cntcity=cnt;
                    cityno=i;
            }
        
        }
        return cityno;
    }
};