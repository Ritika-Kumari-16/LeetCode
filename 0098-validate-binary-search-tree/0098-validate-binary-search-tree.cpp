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
    bool isvalid(TreeNode* root , ll mini , ll maxi){
        if(root==nullptr) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        return isvalid(root->left, mini ,root->val) && isvalid(root->right , root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        return isvalid(root,LLONG_MIN,LLONG_MAX);
    }
};