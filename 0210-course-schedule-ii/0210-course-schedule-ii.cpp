class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>>adj(numCourses);
//         for(auto &it :prerequisites ){
//             adj[it[0]].push_back(it[1]);
//         }
//         vector<int>indegree(numCourses,0);
//         for(int i=0;i<numCourses;i++){
//             for(auto &it :adj[i]){
//                 indegree[it]++;
//             }
//         }
//         queue<int>q;
//         for(int i=0;i<numCourses;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
//         vector<int>ans;
//         while(!q.empty()){
//             int node= q.front();
//             q.pop();
//             ans.push_back(node);
//             for(auto &it :adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0){
//                     q.push(it);
//                 }
//             }
//         }
//         if(ans.size()!=numCourses) return {};
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };