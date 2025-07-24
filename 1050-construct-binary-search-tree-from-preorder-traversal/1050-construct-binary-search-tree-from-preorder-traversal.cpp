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
TreeNode* buildtree(vector<int>&preorder , int &i , int bound){
    if(i==preorder.size() || preorder[i]>bound) return NULL;
    TreeNode* node=new TreeNode(preorder[i]);
    i++;
    node->left=buildtree(preorder,i,node->val);
    node->right=buildtree(preorder,i,bound);
    return node;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        int i=0;
        TreeNode* root=buildtree(preorder,i,INT_MAX);
        return root;
    }
};