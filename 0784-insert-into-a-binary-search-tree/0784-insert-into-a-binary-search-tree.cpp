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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* cur= root;
        while(true){
            if(root->val>val){
                if(root->left ==NULL) {
                    root->left=new TreeNode(val);
                    break;
                }
                else{
                    root=root->left;
                }
                
            }
            else{
                if(root->right==NULL){
                    root->right=new TreeNode(val);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return cur;
    }
};