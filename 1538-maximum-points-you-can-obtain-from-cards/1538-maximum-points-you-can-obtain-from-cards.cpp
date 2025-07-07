class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int maxsum=0;
        int rmax=0;
        for(int i=0;i<k;i++){
            maxsum+=cardPoints[i];
        }
        int r=n-1;
        rmax=maxsum;
        for(int i=k-1;i>=0;i--){
            maxsum-=cardPoints[i];
            maxsum+=cardPoints[r];
            r--;
            rmax=max(rmax,maxsum);
        }
        return rmax;
    }
};