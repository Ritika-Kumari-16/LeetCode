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
void findparent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>&parentmpp){
    queue<TreeNode*>q;
    q.push(root);
    parentmpp[root]=NULL;
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left) {
            parentmpp[node->left]=node;
            q.push(node->left);}

        if(node->right) {
            parentmpp[node->right]=node;
            q.push(node->right);}

    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        unordered_map<TreeNode* , TreeNode*>parentmpp;
        findparent(root,parentmpp);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        q.push(target);
        while(!q.empty()){
            if(k==0) break;
            k--;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentmpp[node]!=NULL && !visited[parentmpp[node]]){
                    q.push(parentmpp[node]);
                    visited[parentmpp[node]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};