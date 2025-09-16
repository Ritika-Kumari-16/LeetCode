class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int sum=0;
        int maxpoints=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        maxpoints=sum;
        int x=k;
        for(int i=n-1;i>=n-k;i--){
            sum-=cardPoints[x-1];
            x--;
            sum+=cardPoints[i];
            maxpoints=max(maxpoints,sum);
        }
        return maxpoints;
    }
};