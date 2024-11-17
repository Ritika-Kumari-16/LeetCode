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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is NULL, return NULL
        if (root == NULL) return NULL;

        // If the current node is p or q, return the current node
        if (root == p || root == q) return root;

        // Recur for the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-NULL, root is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }

        // If only one side returns a result, return that one
        return left != NULL ? left : right;
    }
};