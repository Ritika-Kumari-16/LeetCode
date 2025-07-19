class Solution {
public:
bool dfs(int node, vector<vector<int>>& graph , vector<int>&pathvisited , vector<int>&visited , vector<int>&check){
    visited[node]=1;
    pathvisited[node]=1;
    for(auto &it : graph[node]){
        if(visited[it]==1 && pathvisited[it]==1){
            return true;
        }
        else if( !visited[it]){
            if(dfs(it,graph,pathvisited,visited , check)){
                return true;
            }
        }
    }
    pathvisited[node]=0;
    check[node]=1;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int>pathvisited(N,0);
        vector<int>visited(N,0);
        vector<int>check(N,0);
        for(int i=0;i<N;i++){
            if(!visited[i]){
                if(dfs(i,graph,pathvisited,visited,check));
            }
        }
        vector<int>ans;
        for(int i=0;i<N;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int N= graph.size();
//         vector<vector<int>>adj(N);
//         vector<int>indegree(N,0);
//         for(int i=0;i<N;i++){
//             for(auto &it: graph[i]){
//                 adj[it].push_back(i);
//                 indegree[i]++;
//             }
//         }

//         queue<int>q;
//         vector<int>ans;
//         for(int i=0;i<N;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             ans.push_back(node);
//             for(auto &it :adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0){
//                     q.push(it);
//                 }
//             }
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
        
//     }
// };