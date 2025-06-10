class Solution {
private:
void dfs(int x,int y, vector<vector<int>> &heights ,vector<vector<int>>& vis ){
    int n=heights.size();
    int m=heights[0].size();
    vis[x][y]=1;

    int delx[]={-1,0,1,0};
    int dely[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int newx=x+delx[i];
        int newy=y+dely[i];
// vis mark is must
        if(newx>=0 && newx<n && newy>=0 && newy<m &&!vis[newx][newy] && heights[newx][newy]>=heights[x][y]){
            dfs(newx,newy,heights,vis);
        }
    }
}
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        // set<pair<int,int>> Pacific;
        // set<pair<int,int>> Atlantic;
        vector<vector<int>> res;
        vector<vector<int> > visP(n,vector<int> (m,0));
        vector<vector<int> > visA(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // pacific
                if(i==0 || j==0){
                    dfs(i,j,heights , visP);
                }
                // atlantic
                if(i==n-1 || j==m-1){
                    dfs(i,j,heights , visA );
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visP[i][j]==1 && visA[i][j]==1){
                    res.push_back({i,j});
                }
            }
        }
return res;
    }
};