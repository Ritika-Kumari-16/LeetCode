class Solution {
public:
    void dfs(vector<int>& edges , int start , vector<int>& dist1){
        int dist=0;
        while(start != -1 && dist1[start]==-1){
            dist1[start]=dist;
            dist++;
            start=edges[start];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n,-1);
        vector<int>dist2(n,-1);
        dfs(edges,node1,dist1);
        dfs(edges,node2,dist2);
        int maxdis=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]>=0 && dist2[i]>=0){
                int dis=max(dist1[i],dist2[i]);
                if(dis<maxdis){
                    maxdis=dis;
                    idx=i;
                }
            }
        }
        return idx;
    }
};