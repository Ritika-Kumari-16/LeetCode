class Solution {
public:
void dfs(int row , int col , vector<vector<int>>&image , int initclr , int color){
    int n= image.size();
    int m=image[0].size();
    image[row][col]=color;
    int delrow[]={-1,0,0,1};
    int delcol[]={0,-1,1,0};
    for(int i=0;i<4;i++){
        int nrow=delrow[i]+row;
        int ncol=delcol[i]+col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initclr){
            dfs(nrow,ncol,image,initclr,color);
        }
    }

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        int initclr=image[sr][sc];
        if(initclr==color) return image;
        dfs(sr,sc,image,initclr,color);
        return image;
    }
};