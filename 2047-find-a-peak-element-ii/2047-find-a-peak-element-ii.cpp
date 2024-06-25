int maxeleincol(vector<vector<int>>&arr,int mid,int n){
    int index=-1;
    int maxval=-1;
    for(int i=0;i<n;i++){
        if(arr[i][mid]>maxval){
            maxval=arr[i][mid];
            index=i;
        }
    }
    return index;
}
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m=mat[0].size();
        int low=0 , high=m-1;
        while(low<=high){
            int mid= (low+high)/2;
            int indmx=maxeleincol(mat,mid,n);
            int left,right;
            if(mid-1>=0){
                left=mat[indmx][mid-1];
                }
            else{
                left=-1;
            }
            if(mid+1<=m-1){
                right=mat[indmx][mid+1];
            }
            else {
                right=-1;
            }
            if(left<mat[indmx][mid]&&mat[indmx][mid]>right){
                return {indmx,mid};
            }
            else if(left>mat[indmx][mid]){high=mid-1;}
            else{low=mid+1;}
        
    }
    
    return {-1,-1};
    }
};