class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N= graph.size();
        vector<vector<int>>adj(N);
        vector<int>indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto &it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        vector<int>ans;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it :adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};