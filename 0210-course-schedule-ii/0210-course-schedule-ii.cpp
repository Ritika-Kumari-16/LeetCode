class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &it :prerequisites ){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto &it :adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it :adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};