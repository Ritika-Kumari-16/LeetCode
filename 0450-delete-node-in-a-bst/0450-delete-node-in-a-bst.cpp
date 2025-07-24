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
TreeNode* rightmost(TreeNode* root){
    if(root->right==NULL) return root;
    return rightmost(root->right);
}
TreeNode* helper(TreeNode* root){
    if(root->left==NULL) return root->right;
    if(root->right==NULL) return root->left;
    TreeNode* temp=root->right;
    TreeNode* leftnode=rightmost(root->left);
    leftnode->right=temp;
    return root->left;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key) return helper(root);
        TreeNode* cur=root;
        while(cur){
            if(cur->val<key){
                if(cur->right!=NULL && cur->right->val==key){
                    cur->right=helper(cur->right);
                    break;
                }
                else{
                    cur=cur->right;
                }

            }
            else{
                if(cur->left!=NULL && cur->left->val==key){
                    cur->left=helper(cur->left);
                    break;
                }
                else{
                    cur=cur->left;
                }
            }
        }
        return root;
    }
};