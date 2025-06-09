class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inorder(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inorder[prerequisites[i][0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }     
        while(!q.empty()){
            int cour= q.front();
            q.pop();
            ans.push_back(cour);
            for(auto &it : adj[cour]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }

        }
        if(ans.size() < numCourses) return {};
        return ans;
    }
};