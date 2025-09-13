class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            int maxel=INT_MIN;
            int idx=-1;
            for(int i=0;i<n;i++){
                if(maxel<mat[i][mid]){
                    maxel=mat[i][mid];
                    idx=i;
                }
            }
            int prev= mid==0 ? -1 : mat[idx][mid-1];
            int next=mid==m-1? -1 : mat[idx][mid+1];
            if(maxel > prev && maxel > next) return {idx,mid};
            if(maxel > prev) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};