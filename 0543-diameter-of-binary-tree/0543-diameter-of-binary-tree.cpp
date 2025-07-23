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
int findheight(TreeNode* root , int &ans){
    if(root==NULL) return 0;
    int lh=findheight(root->left,ans);
    int rh=findheight(root->right,ans);
    ans=max(ans,lh+rh);
    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int h= findheight(root,ans);
        return ans;
    }
};