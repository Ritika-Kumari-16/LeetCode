/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findparent(TreeNode* root , unordered_map<TreeNode*, TreeNode*>&parentnode , int startval , TreeNode* &startnode){
        if(root==NULL) return ;
        if(root->val ==startval) {
            startnode=root;
        }
        if(root->left!=NULL) {
            parentnode[root->left]=root;
            findparent(root->left,parentnode,startval,startnode);
        }
        if(root->right!=NULL) {
            parentnode[root->right]=root;
            findparent(root->right,parentnode,startval,startnode);
        }
    }
    bool dfs(TreeNode* root , string &ans,unordered_map<TreeNode*, TreeNode*> & parentnode , unordered_map<TreeNode* , bool>&visited , int destval){
        if(root==NULL) return false;
        if(root->val == destval) return true;
        visited[root]=true;
        if(root->left!=NULL && !visited[root->left] ){
            ans.push_back('L');
            if(dfs(root->left,ans,parentnode,visited,destval)) return true;
            ans.pop_back();
        }
        if(root->right!=NULL && !visited[root->right]){
            ans.push_back('R');
            if(dfs(root->right, ans,parentnode,visited, destval)) return true;
            ans.pop_back();
        }
        if(parentnode[root] && !visited[parentnode[root]]){
            ans.push_back('U');
            if(dfs(parentnode[root], ans,parentnode,visited,destval)) return true;
            ans.pop_back();
        }
        return false;
        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*>parentnode;
        TreeNode* startnode= NULL;
        findparent(root,parentnode,startValue,startnode);
        string ans="";
        unordered_map<TreeNode* , bool>visited;
        if(dfs(startnode,ans,parentnode,visited,destValue)){
            return ans;
        }
        return ans;
    }
};