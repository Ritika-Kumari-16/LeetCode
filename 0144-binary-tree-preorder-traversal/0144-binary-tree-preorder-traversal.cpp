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
    vector<int> solvepreorder(TreeNode* root , vector<int>&ans){
        if(root==NULL) return ans;
        ans.push_back(root->val);
        solvepreorder(root->left,ans);
        solvepreorder(root->right,ans);
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        return solvepreorder(root,ans);
        
    }
};