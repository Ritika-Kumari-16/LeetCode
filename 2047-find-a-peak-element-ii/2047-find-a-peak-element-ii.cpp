class Solution {
public:
    int maxelincol(vector<vector<int>>& mat , int col){
        int maxel=-1;
        int idx=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>maxel){
                maxel=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxelindex=maxelincol(matrix,mid);
            int left=-1,right=-1;
            if(mid-1>=0) left=matrix[maxelindex][mid-1];
            if(mid+1<m) right=matrix[maxelindex][mid+1];
            if(left<matrix[maxelindex][mid] && matrix[maxelindex][mid] > right){
                return {maxelindex,mid};
            }
            else if(matrix[maxelindex][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
        
    }
};