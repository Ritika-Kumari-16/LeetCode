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
typedef long long ll;
bool valid(TreeNode* root, ll maxval , ll minval){
    if(root==NULL) return true;
    if(root->val>=maxval || root->val <=minval) return false;
    return valid(root->left,root->val,minval) && valid(root->right,maxval,root->val);
}
    bool isValidBST(TreeNode* root) {
        ll maxval=LONG_MAX;
        ll minval=LONG_MIN;
        return valid(root,maxval,minval);

    }
};