/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root , unordered_map<TreeNode*, TreeNode*>&parent_tracker){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            if(node->left){
                parent_tracker[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent_tracker[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(target==NULL) return {};
        unordered_map<TreeNode*, TreeNode*>parent_tracker;
        markparents(root,parent_tracker);
        unordered_map<TreeNode* , bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dis=0;
        while(!q.empty()){
            int siz= q.size();
            if(dis==k){
                break;
            }
            dis++;
            for(int i=0;i<siz;i++){
                TreeNode* current= q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_tracker[current] && !visited[parent_tracker[current]]){
                    q.push(parent_tracker[current]);
                    visited[parent_tracker[current]]=true;
                }

            }

        }
        
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
        
    }
};