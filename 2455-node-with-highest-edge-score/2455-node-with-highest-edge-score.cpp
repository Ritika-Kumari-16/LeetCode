class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n= edges.size();
        int mininode=-1;
        long long maxscore=INT_MIN;
        vector<long long>score(n,0);
        for(int i=0;i<n;i++){
            score[edges[i]]+=i;
        }
        for(int i=0;i<n;i++){
            if(score[i]>maxscore){
                maxscore=score[i];
                mininode=i;
            }
        }
        return mininode;
    }
};