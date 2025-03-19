class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int maxsum=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int j=n-1;
        maxsum=max(maxsum,sum);
        for(int i=k-1;i>=0;i--){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            j--;
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};