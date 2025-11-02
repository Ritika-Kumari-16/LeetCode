class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjlist(numCourses);
         vector<int>indeg(numCourses,0);
        for(auto it:prerequisites){
            adjlist[it[1]].push_back(it[0]);
            indeg[it[0]]++;

        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjlist[node]){
                indeg[it]--;
                if(indeg[it]==0) {
                    q.push(it);
                }
            }
        }
        return ans.size() ==numCourses;
    }
};