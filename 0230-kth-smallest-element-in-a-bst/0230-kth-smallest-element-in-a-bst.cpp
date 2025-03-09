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
    void inorder(TreeNode* root , int &cntr , int &k , int &ksmallest){
        if(root==NULL || cntr>=k) return ;
        inorder(root->left, cntr, k , ksmallest);
        cntr++;
        if(cntr==k) {
            ksmallest= root->val;
            return ;
        }
        inorder(root->right, cntr, k, ksmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ksmallest= INT_MIN;
        int cntr=0;
        inorder(root,cntr, k , ksmallest);
        return ksmallest;
        
    }
};