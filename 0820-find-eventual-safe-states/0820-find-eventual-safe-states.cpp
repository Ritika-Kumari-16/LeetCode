class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N= graph.size();
        vector<vector<int>>adjlist(N);
        vector<int>indeg(N,0);
        for(int i=0;i<N;i++){
            for(auto it:graph[i]){
                adjlist[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adjlist[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


// class Solution {
// public:
// bool dfs(int node , vector<vector<int>>&graph ,vector<int>&check, vector<int>&vis, vector<int>&pathvis){
//     vis[node]=1;
//     pathvis[node]=1;
//     for(auto it:graph[node]){
//         if(!vis[it]){
//             if(dfs(it,graph,check,vis,pathvis)==false) return false;
//         }
//         else if(pathvis[it]) return false;
//     }
//     pathvis[node]=0;
//     check[node]=1;
//     return true;
// }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int N=graph.size();
//         vector<int>check(N,0);
//         vector<int>vis(N,0);
//         vector<int>pathvis(N,0);
//         for(int i=0;i<N;i++){
//             if(!vis[i]){
//                 dfs(i,graph,check,vis,pathvis);
//             }
//         }
//         vector<int>result;
//         for(int i=0;i<N;i++){
//             if(check[i]==1) result.push_back(i);
//         }
//         return result;
//     }
// };