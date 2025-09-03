class Solution {
public:
bool static comp (const vector<int>&A , const vector<int>&B){
    if(A[0]==B[0]) return A[1]>=B[1];
    return A[0]<=B[0];
}
    int numberOfPairs(vector<vector<int>>& points) {
        int n= points.size();
        sort(points.begin(),points.end(),comp);
        int totalways=0;
        for(int i=0;i<n;i++){
            int x1= points[i][0];
            int y1=points[i][1];
            int maxy=-1;
            for(int j=i+1;j<n;j++){
                int x2= points[j][0];
                int y2=points[j][1];
                if(y1>=y2  && (maxy<y2 || maxy>y1) ){
                    totalways++;
                    maxy=max(maxy,y2);
                }
                
            }
        }
        return totalways;
    }
};