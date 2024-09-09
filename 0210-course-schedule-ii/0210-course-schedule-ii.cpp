class Solution {
public:
    vector<int>khan(int k,vector<vector<int>>& prerequisites){
        vector<int>graph[k];
        vector<int> degree(k);
       for(auto i:prerequisites){
        graph[i[1]].push_back(i[0]);
        degree[i[0]]++;
       }
       queue<int>q;
       for(int i=0;i<k;i++){
           if(degree[i]==0)q.push(i);
       }
       vector<int>ans;
       while(!q.empty()){
            int i=q.front();
            q.pop();
            ans.push_back(i);
            for(auto it:graph[i]){
              degree[it]--;
              if(degree[it]==0){
                q.push(it);
              }
            }
       }
        return ans;
            }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans=khan(numCourses,prerequisites);
       if(ans.size()<numCourses){
        return {};
       }
         return ans;
    }
};