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
    int lv=findheight(root->left,ans);
    int rv= findheight(root->right,ans);
    lv=max(lv,0);
    rv=max(rv,0);
    int val=lv+rv+root->val;
    ans=max(ans,val);
    return root->val+max(rv,lv);
}
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int h= findheight(root,ans);
        return ans;
    }
};