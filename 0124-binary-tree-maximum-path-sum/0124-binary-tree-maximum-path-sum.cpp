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
    int maxpath( TreeNode* root , int &pathsum){
        if(root == NULL ) return 0;
        int lsum= maxpath(root->left,pathsum);
        int rsum= maxpath(root->right,pathsum);
        int sum = root->val;
        if(lsum> 0 ) sum+=lsum;
        if(rsum>0) sum+=rsum;
        pathsum= max(pathsum , sum);
        if(lsum<0 && rsum< 0 ) return root->val;
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int pathsum =INT_MIN;
        int value= maxpath(root,pathsum);
        return pathsum;
        
    }
};